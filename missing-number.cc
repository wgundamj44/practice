class Solution {
public:
  //check: binary search index
  int missingNumber(vector<int>& nums) {
    int b = 0, e = nums.size() - 1;
    int low = 0, up = nums.size();
    while(b < e) {
      int m = (b + e) / 2;
      swap(nums[b], nums[m]);
      int j = b + 1;
      for(int i = b + 1; i <= e; i++) {
        if (nums[i] <= nums[b]) {
          swap(nums[i], nums[j]);
          j++;
        }
      }
      swap(nums[b], nums[j-1]);
      if (nums[j-1] - low != j - 1 - b) {
        up = nums[j-1] - 1;
        e = j - 2;
      } else {
        low = nums[j-1] + 1;
        b = j;
      }
    }
    if (low == up) return low;
    if (nums[b] == low) return up;
    else return low;
  }
};
