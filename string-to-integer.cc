#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int len = str.length();
    if (len == 0) {
      return 0;
    }
    int i, j, res = 0;
    bool neg = false;
    for(i = 0; i < len; i++) {
      // forward until we find first valid char
      if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '+' || str[i] == '-')) {
	break;
      }
      // only whitespace is allowed before first valid char
      if (str[i] == ' ') {
	continue;
      } else {
	return 0;
      }
    }
    if (i == len) {
      return 0;
    }
    if (str[i] == '+' || str[i] == '-') {
      if (str[i] == '+') neg = false;
      else neg = true;
      i++;
    }
    for(j = i; j < len; j++) {
      if (str[j] >= '0' && str[j] <= '9') {
	int val = (int)(str[j] - '0');
	// deal with overflow
	if (neg) {
	  if (-1 * res < INT_MIN / 10 || (-1 * res == INT_MIN / 10 && -1 * val < INT_MIN % 10)) {
	    return INT_MIN;
	  }
	} else {
	  if (res > INT_MAX / 10 || (res == INT_MAX / 10 && val > INT_MAX % 10)) {
	    return INT_MAX;
	  }
	}
	res = res * 10 + val;
      } else {
	break;
      }
    }
    return res * (neg ? -1 : 1);
  }
};

int main() {
  Solution s;
  cout << s.myAtoi("   +01234 cc1123 ") << endl;
  cout << s.myAtoi("   -01234 cc1123 ") << endl;
  cout << s.myAtoi("   a-01234 cc1123 ") << endl;
  cout << s.myAtoi("   a-1234 cc1123 ") << endl;
  cout << s.myAtoi("   a-1234000 cc1123 ") << endl;
  cout << s.myAtoi("2147483648") << endl;
  cout << s.myAtoi("-2147483649") << endl;
}
