#include<math.h>
#include<iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int k = 10;
        bool over = false;
        while(x / k > 0) {
          if (INT_MAX / 10 < k) {
            over =true;
            break;
          }
          k *= 10;
        }
        if (!over) {
          k /= 10;
        }
        while(x >= 10) {
            if (floor(x / k) != (x % 10)) {
                return false;
            }
            x = (x - floor(x / k) * k - (x % 10)) / 10;
            k  = k /100;
        }
        
        if (x == 0 || k == 1) return true;
        
        return false;
    }
};

int main() {
  Solution *s = new Solution();
  cout << s->isPalindrome(1000000001) << endl;
}
