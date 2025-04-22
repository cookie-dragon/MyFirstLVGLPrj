/**
 * @file cklbase32.h
 * @author My Name (me@domain.com)
 * @brief Powered by libcotp (https://github.com/paolostivanin/libcotp) Apache License 2.0
 * @date 2025-04-22
 *
 * @copyright Copyright (c) My Company 2025
 *
 */

#ifndef CKLBASE32_H
#define CKLBASE32_H

#include <stdint.h>
#include <stdbool.h>

typedef enum cotp_error
{
    NO_ERROR = 0,
    VALID,
    WCRYPT_VERSION_MISMATCH,
    INVALID_B32_INPUT,
    INVALID_ALGO,
    INVALID_DIGITS,
    INVALID_PERIOD,
    MEMORY_ALLOCATION_ERROR,
    INVALID_USER_INPUT,
    EMPTY_STRING,
    MISSING_LEADING_ZERO,
    INVALID_COUNTER,
    WHMAC_ERROR
} cotp_error_t;

typedef unsigned char uchar;

#ifdef __cplusplus
extern "C"
{
#endif

    extern const uint8_t b32_alphabet[];

    char *base32_encode(const uchar *user_data,
                        size_t data_len,
                        cotp_error_t *err_code);

    uchar *base32_decode(const char *user_data_untrimmed,
                         size_t data_len,
                         cotp_error_t *err_code);

    bool is_string_valid_b32(const char *user_data);

#ifdef __cplusplus
}
#endif

#endif // CKLBASE32_H