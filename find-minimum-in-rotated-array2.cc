class Solution {
public:
  //check
  int findMin(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;
    while(nums[0] == nums[e] && e > 0) {
      e--;
    }
    while(s <= e) {
      if (nums[s] <= nums[e]) return nums[s];
      int m = (int)(s + e) / 2;
      if (nums[m] > nums[e]) {
        s = m + 1;
        continue;
      } else {
        e = m;
      }
    }
    return nums[s];
  }
};
