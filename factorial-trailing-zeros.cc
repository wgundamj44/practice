/*
 *  consider fives in (5 * n) * (5 * (n-1) * (5 * (n-2)) ... *  (5 * 1)
 *
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        for(int i = n / 5; i > 0; i = i / 5) {
            sum += i;
        }
        
        return sum;
    }
};
