#include "TreeNode.h"
using namespace std;
// class Solution {
// public:
//   int numDistinct(string s, string t) {
//     if (s.length() == 0 || t.length() == 0) return 0;
//     vector<vector<int>> res = vector<vector<int>>(s.length(), vector<int>(t.length(), 0));
//     for(int i = 0; i < s.length(); i++) {
//       for(int j = 0; j < t.length(); j++) {
//         if (i < j) res[i][j] = 0;
//         else if (j == 0) {
//           if (i == 0) {
//             res[i][j] = s[i] == t[j] ? 1 : 0;
//           } else {
//             res[i][j] = s[i] == t[j] ? res[i-1][j] + 1 : res[i-1][j];
//           }
//         } else {
//           res[i][j] = s[i] == t[j] ? res[i-1][j-1] + res[i-1][j] : res[i-1][j];
//         }
//       }
//     }
//     return res[s.length() - 1][t.length() - 1];
//   }
// };



class Solution {
  //check: DP, one dimension
public:
  int numDistinct(string s, string t) {
    if (s.length() == 0 || s.length() < t.length()) return 0;
    vector<int> res = vector<int>(s.length(), 0);
    vector<int> pre = vector<int>(s.length(), 0);
    for(int i = 0; i < t.length(); i++) {
      for(int j = 0; j < s.length(); j++) {
        if (j < i) res[j] = 0;
        if (i == 0) {
          if (j == 0) {
            res[j] = s[j] == t[i] ? 1 : 0;
          } else {
            res[j] = s[j] == t[i] ? res[j-1] + 1 : res[j-1];
          }
        } else {
         if (s[j] == t[i]) {
            res[j] = pre[j-1] + res[j-1];
          } else {
            res[j] = res[j-1];
          }
        }
      }
      pre = res;
    }
    return res.back();
  }
};

int main() {
  Solution s;
  s.numDistinct("ccc", "c");
}
