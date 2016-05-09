class Solution {
public:
  int countDigitOne(int n) {
    int factor = 1;
    int res = 0;
    while(true) {
      int digit = (n / factor) % 10;
      if (n / factor >= 10) {
        if (digit > 1) {
          res += (n / (factor * 10) + 1) * factor;
        } else if (digit == 1) {
          res += (n / (factor * 10))  * factor + (n % factor + 1);
        } else {
          res += (n / (factor * 10))  * factor;
        }
      } else {
        if (digit > 1) {
          res += factor;
        } else if (digit == 1) {
          res += (n % factor + 1);
        } else {
          res += 0;
        }
        break;
      }
      factor *= 10;
    }
    return res;
  }
};
