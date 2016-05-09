class Solution {
public:
  //check
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    vector<pair<long,long>> s;
    for(int i = 0; i < nums.size(); i++) {
      s.push_back({nums[i], i});
    }
    sort(s.begin(), s.begin() + nums.size(), [](pair<long, long> a, pair<long, long> b) { return a.first < b.first; });
    for(int i = 0; i < nums.size(); i++) {
      int j = i + 1;
      while(abs(s[j].first - s[i].first) <= t) {
        if (j == nums.size()) break;
        if (abs(s[j].second - s[i].second) <= k) {
          return true;
        }
        j++;
      }
    }
    return false;
  }
};
