class Solution {
public:
  bool isPowerOfThree(int n) {
    int maxPower3 = 1162261467;
    if (n <= 0 || n > maxPower3) return false;
    return maxPower3 % n == 0;
  }
};
