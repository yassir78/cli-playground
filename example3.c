#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct MyStructure
{
    int myNum;
    char myLetter;
};

int8_t tadd_ok(int8_t x, int8_t y)
{
    int8_t sum = (x + y);
    return !(x >= 0 && y >= 0 && sum < 0) && !(x < 0 && y < 0 && sum >= 0);
}

/* Determine whether arguments can be added without overflow */
/* WARNING: This code is buggy. */
int tadd_ok(int x, int y)
{
    int sum = x + y;
    int pos_overflow = x > 0 && y > 0 && sum < 0;
    int neg_overflow = (x < 0) && (y < 0) && (sum > 0);
    return !pos_overflow && !neg_overflow;
}

int div16(int x)
{
    /* * Compute x/16 for two's complement integers.
     * To ensure correct rounding toward zero for negative numbers, 
     * we apply a bias of (2^k - 1) before shifting.
     */

    // Extract sign bit to create a mask: 0xFFFFFFFF for negative, 0x0 for positive
    int mask = x >> 31;

    // Apply bias of 15 (0xF) only if x is negative
    return (x + (mask & 0xF)) >> 4;
}

int main()
{
    // uint8_t is an unsigned 8-bit integer (range: 0 to 255)
    uint8_t x = 0b11111111; // 255 in binary
    uint8_t y = 0b11111111; // 255 in binary

    // IMPORTANT:
    // Before doing x + y, C promotes both operands from uint8_t to int
    // So this expression is actually computed as:
    //     (int)x + (int)y = 255 + 255 = 510
    //
    // Then the result (510) is assigned back to uint8_t (8 bits)
    // 510 does NOT fit in 8 bits, so it overflows and wraps:
    //     510 % 256 = 254
    uint8_t z = x + y;

    // NOTE:
    // printf("%d") expects an int, so x, y, and z are promoted to int when passed
    // x = 255, y = 255, z = 254 (after overflow during assignment)
    printf("x = %d, y = %d, sum = %d \n", x, y, z);

    return 0;
}