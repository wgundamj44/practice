class Solution {
public:
  //check
  vector<int> majorityElement(vector<int>& nums) {
    if (nums.size() == 0) return nums;
    set<int> s;
    int a = 0, b = 1;
    int c1 = 0, c2 = 0;
    for(int n : nums) {
      if (a == n) {
        c1++;
      } else if (b == n) {
        c2++;
      } else if (c1 == 0) {
        c1 = 1;
        a = n;
      } else if (c2 == 0) {
        c2 = 1;
        b = n;
      } else {
        c1--;
        c2--;
      }
    }
    c1 = 0, c2 = 0;
    for(int n: nums) {
      if (n == a) c1++;
      if (n == b) c2++;
    }
    if (c1 > nums.size() / 3) s.insert(a);
    if (c2 > nums.size() / 3) s.insert(b);
    vector<int> res(s.begin(), s.end());
    return res;
  }
};
