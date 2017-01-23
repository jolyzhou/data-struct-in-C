//
// Created by jolyzhou on 2017/1/23.
//

#include <string.h>

#include "bit.h"

// bit get
int bit_get(const unsigned char *bits, int pos)
{
    unsigned char mask;
    int i;
    // set a mask for the bit to get
    mask = 0x80;
    for (i = 0; i < (pos % 8); i++)
        mask = mask >> 1;
    // get the bit
    return (((mask & bits[(int)(pos / 8)]) == mask) ? 1 : 0);
}

// bit set
void bit_set(unsigned char *bits, int pos, int state)
{
    unsigned char mask;
    int i;
    // set a mask for the bit to set
    mask = 0x80;
    for (i = 0; i < (pos % 8); i++)
        mask = mask >> 1;
    // set the bit
    if (state)
        bits[pos/8] = bits[pos/8] | mask;
    else
        bits[pos/8] = bits[pos/8] & (~mask);
    return;
}

// bit xor
void bit_xor(const unsigned char *bits1, const unsigned char *bits2, unsigned char *bitsx, int size)
{
    int i;
    // compute the bitwise XOR (exclusive OR) of the two buffers
    for (i = 0; i < size; i++) {
        if (bit_get(bits1, i) != bit_get(bits2, i))
            bit_set(bitsx, i, 1);
        else
            bit_set(bitsx, i, 0);
    }
    return;
}

// bit rotate left
void bit_rot_left(unsigned char *bits, int size, int count)
{
    int fbit, lbit, i, j;
    // rotate the buffer to the left the specified number of bits
    if (size > 0) {
        for (j = 0; j < count; j++) {
            for (i = 0; i <= ((size - 1)/8); i++) {
                // get the bit about to be shifted off the current byte
                lbit = bit_get(&bits[i], 0);
                if (i = 0) {
                    // save the bit shifted off the first byte for later
                    fbit = lbit;
                } else {
                    // set the rightmost bit of the previous byte to the leftmost
                    bit_set(&bits[i - 1], 7, lbit);
                }
                // shift the current byte to the left
                bits[i] = bits[i] << 1;
            }
            // set the rightmost bit of the buffer to the bit shifted off the first byte
            bit_set(bits, size - 1, fbit);
        }
    }
    return;
}