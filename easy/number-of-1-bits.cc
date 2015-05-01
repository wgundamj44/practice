class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        uint32_t bit;
        while(n > 0) {
            bit = n & 0x01;
            n = n >> 1;
            if (bit == 1) {
                res++;
            }
        }
        
        return res;
    }
};