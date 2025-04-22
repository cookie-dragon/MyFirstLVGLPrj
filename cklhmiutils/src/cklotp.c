#include "cklotp.h"

#include <string.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

#include "cklbase32.h"

static const int8_t base32_vals[256] = {
    //    This map cheats and interprets:
    //       - the numeral zero as the letter "O" as in oscar
    //       - the numeral one as the letter "L" as in lima
    //       - the numeral eight as the letter "B" as in bravo
    // 00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0x00
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0x10
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0x20
    14, 11, 26, 27, 28, 29, 30, 31, 1, -1, -1, -1, -1, 0, -1, -1,   // 0x30
    -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,           // 0x40
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, // 0x50
    -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,           // 0x60
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, -1, -1, -1, -1, // 0x70
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0x80
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0x90
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0xA0
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0xB0
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0xC0
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0xD0
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0xE0
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0xF0
};

int validate_b32key(char *k, size_t len, size_t pos)
{

    // validates base32 key
    if (((len & 0xF) != 0) && ((len & 0xF) != 8))
        return 1;
    for (pos = 0; (pos < len); pos++)
    {
        if (base32_vals[k[pos]] == -1)
            return 1;
        if (k[pos] == '=')
        {
            if (((pos & 0xF) == 0) || ((pos & 0xF) == 8))
                return (1);
            if ((len - pos) > 6)
                return 1;
            switch (pos % 8)
            {
            case 2:
            case 4:
            case 5:
            case 7:
                break;
            default:
                return 1;
            }
            for (; (pos < len); pos++)
            {
                if (k[pos] != '=')
                    return 1;
            }
        }
    }
    return 0;
}

size_t decode_b32key(uint8_t **k, size_t len)
{

    size_t keylen;
    size_t pos;
    // decodes base32 secret key
    keylen = 0;
    for (pos = 0; pos <= (len - 8); pos += 8)
    {
        // MSB is Most Significant Bits  (0x80 == 10000000 ~= MSB)
        // MB is middle bits             (0x7E == 01111110 ~= MB)
        // LSB is Least Significant Bits (0x01 == 00000001 ~= LSB)

        // byte 0
        (*k)[keylen + 0] = (base32_vals[(*k)[pos + 0]] << 3) & 0xF8;  // 5 MSB
        (*k)[keylen + 0] |= (base32_vals[(*k)[pos + 1]] >> 2) & 0x07; // 3 LSB
        if ((*k)[pos + 2] == '=')
        {
            keylen += 1;
            break;
        }

        // byte 1
        (*k)[keylen + 1] = (base32_vals[(*k)[pos + 1]] << 6) & 0xC0;  // 2 MSB
        (*k)[keylen + 1] |= (base32_vals[(*k)[pos + 2]] << 1) & 0x3E; // 5  MB
        (*k)[keylen + 1] |= (base32_vals[(*k)[pos + 3]] >> 4) & 0x01; // 1 LSB
        if ((*k)[pos + 4] == '=')
        {
            keylen += 2;
            break;
        }

        // byte 2
        (*k)[keylen + 2] = (base32_vals[(*k)[pos + 3]] << 4) & 0xF0;  // 4 MSB
        (*k)[keylen + 2] |= (base32_vals[(*k)[pos + 4]] >> 1) & 0x0F; // 4 LSB
        if ((*k)[pos + 5] == '=')
        {
            keylen += 3;
            break;
        }

        // byte 3
        (*k)[keylen + 3] = (base32_vals[(*k)[pos + 4]] << 7) & 0x80;  // 1 MSB
        (*k)[keylen + 3] |= (base32_vals[(*k)[pos + 5]] << 2) & 0x7C; // 5  MB
        (*k)[keylen + 3] |= (base32_vals[(*k)[pos + 6]] >> 3) & 0x03; // 2 LSB
        if ((*k)[pos + 7] == '=')
        {
            keylen += 4;
            break;
        }

        // byte 4
        (*k)[keylen + 4] = (base32_vals[(*k)[pos + 6]] << 5) & 0xE0;  // 3 MSB
        (*k)[keylen + 4] |= (base32_vals[(*k)[pos + 7]] >> 0) & 0x1F; // 5 LSB
        keylen += 5;
    }
    (*k)[keylen] = 0;

    return keylen;
}

uint8_t *hmac(unsigned char *key, int kl, uint64_t interval)
{

    return (uint8_t *)HMAC(EVP_sha1(), key, kl,
                           (const unsigned char *)&interval, sizeof(interval), NULL, 0);
}

uint32_t DT(uint8_t *digest)
{

    uint64_t offset;
    uint32_t bin_code;

#ifdef DEBUG

    char mdString[40];
    for (int i = 0; i < 20; i++)
        sprintf(&mdString[i * 2], "%02x", (unsigned int)digest[i]);
    printf("HMAC digest: %s\n", mdString);

#endif

    // dynamically truncates hash
    offset = digest[19] & 0x0f;

    bin_code = (digest[offset] & 0x7f) << 24 | (digest[offset + 1] & 0xff) << 16 | (digest[offset + 2] & 0xff) << 8 | (digest[offset + 3] & 0xff);

    // truncates code to 6 digits
#ifdef DEBUG
    printf("OFFSET: %d\n", offset);
    printf("\nDBC1: %d\n", bin_code);
#endif

    return bin_code;
}

uint32_t mod_hotp(uint32_t bin_code, int digits)
{
    int power = pow(10, digits);
    uint32_t otp = bin_code % power;

    return otp;
}

uint32_t HOTP(uint8_t *key, size_t kl, uint64_t interval, int digits)
{

    uint8_t *digest;
    uint32_t result;
    uint32_t endianness;

#ifdef DEBUG
    printf("KEY IS: %s\n", key);
    printf("KEY LEN IS: %d\n", kl);
    printf("COUNTER IS: %d\n", interval);
#endif

    endianness = 0xdeadbeef;
    if ((*(const uint8_t *)&endianness) == 0xef)
    {
        interval = ((interval & 0x00000000ffffffff) << 32) | ((interval & 0xffffffff00000000) >> 32);
        interval = ((interval & 0x0000ffff0000ffff) << 16) | ((interval & 0xffff0000ffff0000) >> 16);
        interval = ((interval & 0x00ff00ff00ff00ff) << 8) | ((interval & 0xff00ff00ff00ff00) >> 8);
    };
    // First Phase, get the digest of the message using the provided key ...
    digest = (uint8_t *)hmac(key, kl, interval);
    // digest = (uint8_t *)HMAC(EVP_sha1(), key, kl, (const unsigned char *)&interval, sizeof(interval), NULL, 0);

    // Second Phase, get the dbc from the algorithm
    uint32_t dbc = DT(digest);
    // Third Phase: calculate the mod_k of the dbc to get the correct number
    result = mod_hotp(dbc, digits);

    return result;
}

time_t get_time(time_t t0)
{
    return floor((time(NULL) - t0) / TS);
}

uint32_t TOTP(uint8_t *key, size_t kl, uint64_t time, int digits)
{
    uint32_t totp;

    totp = HOTP(key, kl, time, digits);
    return totp;
}

uint32_t get_totp_demo()
{
#define T0 0
#define DIGITS 6
#define VALIDITY 30
#define TIME 30
// Maximum size for base32 secrets
#define MAX_SECRET_LEN 64

    static char sec[MAX_SECRET_LEN];

    char *pname = "Cooky.Long";

    cotp_error_t cotp_err;
    char *psecret = base32_encode(pname, strlen(pname) + 1, &cotp_err); // b32_secretkey

    size_t pos, len, kl;
    uint8_t *key;

    len = strlen(psecret);

    if (len >= MAX_SECRET_LEN)
    {
        fprintf(stderr, "%s: key len error\n", pname);
        return -1;
    }

    if (validate_b32key(psecret, len, pos) == 1)
    {
        fprintf(stderr, "ERR %s: invalid base32 secret\n", pname);
        return -1;
    }

    strncpy(sec, psecret, MAX_SECRET_LEN - 1);
    sec[MAX_SECRET_LEN - 1] = '\0';
    key = (uint8_t *)&sec;
    kl = decode_b32key(&key, len);

    time_t t = floor((time(NULL) - T0) / VALIDITY);
    uint32_t totp = HOTP(key, kl, t, DIGITS);

    return totp;
}