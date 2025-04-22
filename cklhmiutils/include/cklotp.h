/**
 * @file cklotp.h
 * @author My Name (me@domain.com)
 * @brief Powered by c_otp (https://github.com/fmount/c_otp) MIT License
 * @date 2025-04-22
 *
 * @copyright Copyright (c) My Company 2025
 *
 */

#ifndef CKLOTP_H
#define CKLOTP_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define TS 30 /* time step in seconds, default value */

#ifdef __cplusplus
extern "C"
{
#endif

    int validate_b32key(char *k, size_t len, size_t pos);
    size_t decode_b32key(uint8_t **k, size_t len);

    // MAIN HOTP function
    uint32_t HOTP(uint8_t *key, size_t kl, uint64_t interval, int digits);
    // First step
    uint8_t *hmac(unsigned char *key, int kl, uint64_t interval);
    // Second step
    uint32_t DT(uint8_t *digest);

    /******** RFC6238 **********
     *
     * TOTP = HOTP(k,T) where
     * K = the supersecret key
     * T = ( Current Unix time - T0) / X
     * where X is the Time Step
     *
     * *************************/
    uint32_t TOTP(uint8_t *key, size_t kl, uint64_t time, int digits);
    time_t get_time(time_t T0);

    uint32_t get_totp_demo();

#ifdef __cplusplus
}
#endif

#endif // CKLOTP_H