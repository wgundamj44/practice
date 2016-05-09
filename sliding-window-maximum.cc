class Solution {
public:
  //check
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<vector<int>::iterator> q;
    vector<int> res;
    if (nums.size() == 0) return res;
    for(int i = 0; i < k; i++) {
      q.push_back(nums.begin() + i);
      for(auto it = q.begin() + q.size() - 1; q.size() > 1 && **it >= **(it - 1);) {
        q.erase(it - 1);
        it = q.begin() + q.size() - 1;
      }
    }
    res.push_back(**q.begin());
    int i = k;
    while(i < nums.size()) {
      if (*q.begin() == nums.begin() + i - k) {
        q.erase(q.begin());
      }
      q.push_back(nums.begin() + i);
      for(auto it = q.begin() + q.size() - 1; q.size() > 1 && **it > **(it - 1);) {
        q.erase(it - 1);
        it = q.begin() + q.size() - 1;
      }
      res.push_back(**q.begin());
      i++;
    }
    return res;
  }
};
