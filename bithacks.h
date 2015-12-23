#ifndef BITHACKS_H
#define BITHACKS_H

#include "datasizes.h"

u32 ilog2(u32 v) {
    static const uint MultiplyDeBruijnBitPosition[32] = {
        1, 10, 2, 11, 14, 22, 3, 30, 12, 15, 17, 19, 23, 26, 4, 31,
        9, 13, 21, 29, 16, 18, 25, 8, 20, 28, 24, 7, 27, 6, 5, 32
    };
    
    v |= v >> 1; // first round down to one less than a power of 2 
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    
    return MultiplyDeBruijnBitPosition[(u32)(v * 0x07C4ACDDU) >> 27];
}

#endif //BITHACKS_H
