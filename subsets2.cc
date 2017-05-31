#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  //check
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res = {{}};
    int pre;
    for(int i = 0; i < nums.size(); i++) {
      if (i == 0 || nums[i] != nums[i-1]) {
	pre = res.size();
      }
      int s = res.size();
      for(int j = s - pre; j < s; j++) {
	auto tmp = res[j];
	tmp.push_back(nums[i]);
	res.push_back(tmp);
      }
    }
    return res;
  }
};
  // BAD!
  // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  //   sort(nums.begin(), nums.end());
  //   map<int, int> m;
  //   vector<int> uni;
  //   vector<vector<int>> res;
  //   for(auto n : nums) {
  //     if (m.find(n) == m.end()) {
  // 	m[n] = 1;
  // 	uni.push_back(n);
  //     } else {
  // 	m[n]++;
  //     }
  //   }
  //   auto ret = solve(uni);
  //   for(auto sol : ret) {
  //     auto tmp = addDup(0, sol, m);
  //     for(auto t: tmp) {
  // 	res.push_back(t);
  //     }
  //   }
  //   return res;
  // }

  // vector<vector<int>> addDup(int i, vector<int>& sol, map<int, int>& m) {
  //   if (i == sol.size()) {
  //     return {{}};
  //   }
  //   int v = sol[i];
  //   auto sub = addDup(i + 1, sol, m);
  //   vector<vector<int>> ret;
  //   for(int j = 1; j <= m[v]; j++) {
  //     for(auto s : sub) {
  // 	auto tmp = vector<int>(j, v);
  // 	tmp.insert(tmp.end(), s.begin(), s.end());
  // 	ret.push_back(tmp);
  //     }
  //   }
  //   return ret;
  // }

  // vector<vector<int>> solve(vector<int>& nums) {
  //   vector<vector<int>> ret;
  //   if (nums.size() == 0) return ret;

  //   if (nums.size() == 1) return {{}, {nums[0]}};
  //   int last = nums[nums.size() - 1];
  //   nums.pop_back();
  //   auto res = solve(nums);
  //   ret = res;
  //   for(auto it:  res) {
  //     vector<int> tmp = it;
  //     tmp.push_back(last);
  //     ret.push_back(tmp);
  //   }

  //   return ret;
  // }
