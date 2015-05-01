class Solution {
public:
    int reverse(int x) {
        bool minus = false;
        if (x < 0) {
            minus = true;
            x = -1 * x;
        }
        int ret = 0;
        while(x > 0) {
            int re = x % 10;
            x = (int)(x / 10);
            if ((INT_MAX - re) / 10 < ret) {
                ret = 0;
                break;
            }
            ret = ret * 10 + re;
        }
        
        return minus ? -1 * ret : ret;
    }
};
