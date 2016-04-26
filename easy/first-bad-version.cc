// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int b = 1, e = n, last = 0;
    while(b < e) {
      int m = b + (e - b) / 2;
      if (m == last) return m;
      if (isBadVersion(m)) {
        e = m;
        last = m;
      } else {
        b = m + 1;
      }
    }
    return b;
  }
};
