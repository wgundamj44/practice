class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    vector<int> a1, a2;
    for(int n : nums) {
      if (a1.size() == 0) {
        a1.push_back(n);
      } else if (a1.size() == 1) {
        if (n > a1[0]) {
          a1.push_back(n);
        } else {
          a1[0] = n;
        }
      } else if (a1.size() == 2) {
        if (n > a1[1]) return true;
        else if (n <= a1[1] && n > a1[0]) {
          a1[1] = n;
        } else if (n < a1[0]) {
          if (a2.size() == 0) {
            a2.push_back(n);
          } else if (a2.size() == 1) {
            if (n > a2[0]) {
              a2.push_back(n);
              a1 = a2;
              a2.clear();
            } else {
              a2[0] = n;
            }
          }
        }
      }
    }
    return false;
  }
};
