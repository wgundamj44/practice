class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);
    return max(nums[0] + findMax(nums, 2, nums.size() - 2), findMax(nums, 1, nums.size()-1));
  }

  int findMax(vector<int>& nums, int b, int e) {
    if (b > e) return 0;
    int pre = 0, cur = 0;
    for(int i = b ; i <=e ;i++) {
      if (i == b) {
        cur = nums[i];
      } else {
        int tmp = cur;
        cur = max(nums[i] + pre, cur);
        pre=  tmp;
      }
    }
    return cur;
  }
};
