class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int res, con;
    for(int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        res = nums[i];
        con = nums[i];
      }
      else {
          con = max(nums[i], con + nums[i]);
          res = max(res, con);
      }
    }
    return res;
  }
};


