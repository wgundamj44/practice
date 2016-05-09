class Solution {
public:
  //check
  int rangeBitwiseAnd(int m, int n) {
    int mask = 1, res = m, l = -1, tmp = n;
    while(true) {
      if ((m & mask) != (n & mask)) {
        res = res & (l << 1);
      }
      tmp = tmp >> 1;
      l = l << 1;
      mask = mask << 1;
      if (tmp == 0) break;
    }
    return res;
  }

};
