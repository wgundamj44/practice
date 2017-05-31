#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int n1 = n % 2 == 0 ? n / 2 : n / 2;
    int n2 = n % 2 == 0 ? n / 2 : n / 2 + 1;
    return max(n1, integerBreak(n1)) * max(n2, integerBreak(n2));
  }
};

int main() {
  Solution s;
  cout << s.integerBreak(7) << endl;
}
