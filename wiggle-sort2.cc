class Solution {
public:
  //check
  void wiggleSort(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + (nums.size() - 1) / 2, nums.end());
    int m1 = *(nums.begin() + (nums.size() -1) / 2);
    vector<int> l, m, r;
    for(int i : nums) {
      if (i < m1) {
        l.push_back(i);
      } else if (i > m1) {
        r.push_back(i);
      } else {
        m.push_back(i);
      }
    }
    int cl, cr;
    if (nums.size() % 2 == 0) {
      cl = nums.size() / 2;
      cr = nums.size() / 2;
    } else {
      cl = nums.size() / 2 + 1;
      cr = nums.size() / 2;
    }
    int i = 0, j = 0;
    for(; i < cl - l.size(); i++) {
      nums[j] = m[i];
      j += 2;
    }
    for(int k = 0; k < l.size(); k++) {
      nums[j] = l[k];
      j += 2;
    }
    j = 1;
    for(int k =0; k < r.size(); k++) {
      nums[j] = r[k];
      j += 2;
    }
    for(; i < m.size(); i++) {
      nums[j] = m[i];
      j += 2;
    }
  }
};
