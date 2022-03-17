// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    uint64_t w;
    double g = 1;
    for (w = 1; w <= n; w++)
        g *= value;
    return g;
}

uint64_t fact(uint16_t n) {
    if (n == 0)
        return 1;
    return fact(n-1)*n;
}
double calcItem(double g, uint16_t n) {
    return pown(g, n)/fact(n);
}
double expn(double g, uint16_t count) {
    uint16_t w;
    double v;
    for (w = 0; w <= count; w++) {
        v += calcItem(g, w);
    }
    return v;
}
double sinn(double g, uint16_t count) {
    uint16_t w;
    double v = 0;
    for (w = 1; w <= count; w++) {
        v += pown(-1, w-1)*calcItem(g, 2*w-1);
    }
    return v;
}
double cosn(double g, uint16_t count) {
    uint16_t w;
    double v = 0;
    for (w = 1; w <= count; w++) {
        v += pown(-1, w-1)*calcItem(g, 2*w-2);
    }
    return v;
}
