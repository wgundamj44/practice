class Solution {
public:
  //check
  int coinChange(vector<int>& coins, int amount) {
    vector<int> res(amount + 1, -1);
    res[0] = 0;
    for(int i = 0; i < amount + 1; i++) {
      for(int j = 0; j < coins.size(); j++) {
        if (i - coins[j] >= 0) {
          if (res[i-coins[j]] == -1) {
            continue;
          } else {
            if (res[i] == -1) {
              res[i] = res[i-coins[j]] + 1;
            } else {
              res[i] = res[i-coins[j]] + 1 < res[i] ? res[i-coins[j]] + 1 : res[i];
            }
          }
        }
      }
    }
    return res[amount];
  }
};
