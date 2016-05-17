//check
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        if (nums[i] > 0 ) {
          res = {nums[i], nums[i], 1};
        } else if (nums[i] < 0) {
          res = {nums[i], -1, nums[i]};
        } else {
          res = {nums[i], -1, 1};
        }
      } else {
        if (nums[i] > 0) {
          if (res[1] > 0) {
            res[1] = res[1] * nums[i];
          } else {
            res[1] = nums[i];
          }
          if (res[2] < 0) {
            res[2] = res[2] * nums[i];
          } else {
            res[2] = 1;
          }
          res[0] = res[1] > res[0] ? res[1] : res[0];
        } else if (nums[i] < 0){
          int tmp = res[1];
          res[1] = res[2] < 0 ? res[2] * nums[i] : -1;
          res[2] = tmp > 0 ? tmp * nums[i] : nums[i];
          res[0] = res[1] > res[0] ? res[1] : res[0];
        } else {
          res[1] = -1;
          res[2] = 1;
          if (nums[i] > res[0]) res[0] = nums[i];
        }
      }
    }
    return res[0];
  }
};
