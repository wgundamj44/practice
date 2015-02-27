#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;

        int min = prices[0];
        int maxProfit = 0;
        for(auto it = prices.begin() + 1; it != prices.end(); it++) {
            if (*it >= min) {
                if (*it - min > maxProfit) {
                    maxProfit = *it - min;
                }
            } else {
                min = *it;
            }
        }
        return maxProfit;
    }
};
