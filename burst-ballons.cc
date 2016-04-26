class Solution {
public:
  //check
  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for(int len = 1; len <= n - 2; len++) {
      for(int i = 0; i <= n - len - 2; i++) {
        int j = i + len + 1;
        for(int k = i + 1; k <= j - 1; k++) {
          res[i][j] = max(res[i][j], res[i][k] + res[k][j] + nums[i] * nums[k] * nums[j]);
        }
      }
    }
    return res[0][n-1];
  }
};
