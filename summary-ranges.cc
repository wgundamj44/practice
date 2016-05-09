class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    for(int i = 0;i < nums.size(); i++) {
      int j = i;
      for(; j < nums.size() - 1; j++) {
        if (nums[j + 1] - nums[j] != 1) {
          break;
        }
      }
      if (i == j) {
        res.push_back(to_string(nums[i]));
      } else {
        string s = to_string(nums[i]) + "->" + to_string(nums[j]);
        res.push_back(s);
      }
      i = j;
    }
    return res;
  }
};
