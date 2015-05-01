class Solution {
public:
    bool isHappy(int n) {
        set<int> res;
        while(true) {
            int sum = 0;
            while(n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (sum == 1) return true;
            if (res.find(sum) != res.end()) {
                return false;
            }
            res.insert(sum);
            n = sum;
        }
    }
};