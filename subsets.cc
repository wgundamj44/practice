#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return solve(nums);
  }

  vector<vector<int>> solve(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.size() == 0) return ret;

    if (nums.size() == 1) return {{}, {nums[0]}};
    int last = nums[nums.size() - 1];
    nums.pop_back();
    auto res = solve(nums);
    ret = res;
    for(auto it:  res) {
      vector<int> tmp = it;
      tmp.push_back(last);
      ret.push_back(tmp);
    }

    return ret;
  }
};
