class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int s = 0, c = 0, c1 = 0;
    for(int i = 0; i < prices.size(); i++) {
      if (i == 0) {
        s = -1 * prices[i], c = 0; c1 = 0;
      } else {
        int tmp = c;
        c = max(c, s + prices[i]);
        s = max(c1 - prices[i], s);
        c1 = tmp;
      }
    }
    return max(c, s);
  }
};
