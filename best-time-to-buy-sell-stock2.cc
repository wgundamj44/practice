#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int pre = -1;
        int profit = 0;
        for(int& i: prices) {
            if (pre == -1) {
                pre = i;
            } else {
                if (i >= pre) {
                    profit += (i - pre);
                    pre = i;
                } else {
                    pre = i;
                }
            }
        }
        return profit;
    }
};
