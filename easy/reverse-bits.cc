class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++) {
            uint32_t bit = n & 0x01;
            res = (res << 1) | bit;
            n = n >> 1;
        }
        
        return res;
    }
};