class Solution {
public:
  //check: greedy
  int jump(vector<int>& nums) {
    int maxRange = 0, next = 0, current = 0, step = 0;
    if (nums.size() <= 1) return 0;
    while(true) {
      maxRange = 0;
      for(int i = 1; i <= nums[current]; i++) {
        if (i + current >= nums.size() - 1) return step + 1;
        if (maxRange < current + i + nums[current + i]) {
          maxRange = current + i + nums[current + i];
          next = current + i;
        }
      }
      if (maxRange == 0) return 0;
      current = next;
      step++;
    }
  }
};
