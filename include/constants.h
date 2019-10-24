//
// Created by Aargo on 10/17/2019.
//

#ifndef NAMESORT_CONSTANTS_H
#define NAMESORT_CONSTANTS_H

#include <stdint.h>

#define MIN_VEC_SIZE 8
#define MAX_STR_SIZE 255

#define min(X,Y) ((X) < (Y) ? (X) : (Y))
#define max(X,Y) ((X) > (Y) ? (Y) : (X))

/*
 * The C Spec does not guarantee an exact 8/16/32/64-bit size for every platform
 * So even though uint8_t is defined on most platforms, it is not guaranteed.
 * Likewise for the other types. Instead, it is safter to use the leastX types,
 * since they are guaranteed on every platform if at all possible.
 */
typedef uint_least8_t uint8;
typedef uint_least16_t uint16;
typedef uint_least32_t uint32;
typedef uint_least64_t uint64;

/*
 * Typedef for string length so if we change our minds about their max length
 * later we can just change the typedef here.
 */
typedef uint8 strlen_t;

#endif //NAMESORT_CONSTANTS_H
