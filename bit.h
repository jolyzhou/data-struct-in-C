//
// Created by jolyzhou on 2017/1/23.
//

#ifndef DATA_STRUCT_BIT_H
#define DATA_STRUCT_BIT_H

int bit_get(const unsigned char *bits, int pos);
void bit_set(unsigned char *bits, int pos, int state);
void bit_xor(const unsigned char *bits1, const unsigned char *bits2, unsigned char *bitsx, int size);
void bit_rot_left(unsigned char *bits, int size, int count);
#endif //DATA_STRUCT_BIT_H
