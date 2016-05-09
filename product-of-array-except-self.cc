class Solution {
public:
  //check
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res;
    if (nums.size() == 0) return res;
    vector<int> v1(nums.size()), v2(nums.size());
    for(int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        v1[0] = 1;
        v2[nums.size()-1] = 1;
      } else {
        v1[i] = nums[i-1] * v1[i-1];
        v2[nums.size() - 1 - i] = (nums[nums.size() - i ] * v2[nums.size() - i]);
      }
    }
    for(int i = 0; i < nums.size(); i++) {
      res.push_back(v1[i] * v2[i]);
    }
    return res;
  }
};
