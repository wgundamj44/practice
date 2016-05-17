class Solution {
public:
  //check
  int maxProfit(int k, vector<int>& prices) {
    if (k >= prices.size() / 2) {
      int res = 0;
      for(int i = 0 ; i< (int)(prices.size()) - 1; i++) {
        if (prices[i+1] > prices[i]) {
          res += (prices[i+1] - prices[i]);
        }
      }
      return res;
    } else {
      int len = prices.size();
      if (k ==0) return 0;
      //vector<vector<int>> sold = vector<vector<int>>(len, vector<int>(k, INT_MIN));
      //vector<vector<int>> hold = vector<vector<int>>(len, vector<int>(k, INT_MIN));
      vector<int> sold = vector<int>(k, INT_MIN);
      vector<int> hold = vector<int>(k, INT_MIN);
      for(int i = 0; i < len ;i++) {
        int pre_sold = INT_MIN;
        for(int j = 0; j < k; j++) {
          if (i == 0) {
            hold[0] = -1 * prices[i];
          } else {
            if (j == 0) {
              hold[0] = max(-1 * prices[i], hold[j]);
            } else {
              if (pre_sold != INT_MIN) {
                hold[j] = max(pre_sold - prices[i], hold[j]);
              }
            }
            if (hold[j] != INT_MIN) {
              pre_sold = sold[j];
              sold[j] = max(hold[j] + prices[i], sold[j]);
            }
          }
        }
      }
      return *max_element(sold.begin(), sold.end());
    }
  }
};
