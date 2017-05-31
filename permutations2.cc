#include "common.h"
using namespace std;

class Solution {
public:
  //check!
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    permute(nums, res, 0);
    return res;
  }

  void permute(vector<int>& nums, vector<vector<int>>& res, int s) {
    if (s == nums.size()) {
      res.push_back(nums);
      return;
    }
    for(int i = s; i < nums.size(); i++) {
      bool flag = false;
      for(int j = s; j < i; j++) {
        if (nums[j] == nums[i]) {
          flag = true;
          break;
        }
      }
      if (flag) continue;
      swap(nums[i], nums[s]);
      permute(nums, res, s + 1);
      swap(nums[i], nums[s]);
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = { 1 , 1, 1, 2, 3};
  auto res = s.permuteUnique(nums);
  for (auto vs : res) {
    for(auto v: vs) {
      cout << v << " ";
    }
    cout << endl;
  }
  cout << res.size() << endl;
}
