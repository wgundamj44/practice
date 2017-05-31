#include<iostream>
using namespace std;

// !!! clear mind

// class Solution {
// public:
//   int numDecodings(string s) {
//     int len = s.length();
//     int cur = 0, pre = 0;
//     if (s.length() == 0) return 0;

//     cur = s[len - 1] == '0' ? 0 : 1;
//     pre = 1;
//     for(int i = len - 2; i >= 0; i--) {
//       int tmp = 0, tmp1 = cur;
//       if (s[i] == '0' || (s[i] >= '3' && s[i+1] == '0')) {
// 	tmp = 0;
//       } else {
// 	if (s[i] == '1' || (s[i] == '2' && s[i+1] <='6')) {
// 	  tmp += pre;
// 	}
// 	if (s[i] != '0') {
// 	  tmp += cur;
// 	}
//       }
//       cur = tmp;
//       pre = tmp1;
//     }
//     return cur;
//   }
// };

class Solution {
public:
  int numDecodings(string s) {
    if (s.length() == 0) return 0;
    int cur = 0, pre = 0, pre2 = 0;
    for(int i = 0; i < s.length(); i++) {
      if (i == 0) cur = (s[i] >= '1' && s[i] <= '9') ? 1 : 0;
      else {
        cur = (s[i] >= '1' && s[i] <= '9') ? pre : 0;
        if (s[i-1] != '0' && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))) {
          if (i == 1) {
            cur += 1;
          } else {
            cur += pre2;
          }
        }
      }
      pre2 = pre;
      pre = cur;
    }
    return cur;
  }
};
