class Solution {
public:
  //check
  int minSubArrayLen(int s, vector<int>& nums) {
    int i = 0, j = 0, len = nums.size();
    int sum = 0, res = -1;
    while(i < len) {
      while(sum < s) {
        if (j == len) break;
        sum += nums[j];
        j++;
      }
      if (sum >= s) {
        if (res < 0) res = j - i;
        else res = j - i < res ? j - i : res;
      }  else {
        return res < 0 ? 0 : res;
      }
      sum -= nums[i];
      i++;
    }
    return res < 0 ? 0 : res;
  }
};
