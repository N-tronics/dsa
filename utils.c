#include "utils.h"

int toPosIdx(int max, int idx) {
    if (idx >= 0) return idx;
    int pos = max + idx;
    return pos < 0 ? 0 : pos;
}

void intSwap(int *a, int *b) {
    int t = *b;
    *b = *a;
    *a = t;
}