class Solution {
public:
  //check
  int minPatches(vector<int>& nums, int n) {
    long maxReach = 0;
    int res = 0;
    int i = 0;
    while(true) {
      if (maxReach < n) {
        if (i < nums.size()) {
          if (maxReach + 1< nums[i]) {
            res++;
            maxReach = maxReach + maxReach + 1;
          } else {
            maxReach += nums[i];
            i++;
          }
        } else {
          res++;
          maxReach = maxReach + maxReach + 1;
        }
      } else {
        return res;
      }
    }
  }
};
