long flippingBits(long n) {
    long mask = 1;
    for (int i = 0; i < 32; ++i) {
        n ^= mask;
        mask <<= 1;
    }
    return n;    
}
