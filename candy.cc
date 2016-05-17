#include "TreeNode.h"
using namespace std;
//check
// class Solution {
// public:
//   int candy(vector<int>& ratings) {
//     int len = ratings.size();
//     int res = 0;
//     int c = 0;
//     for(int i = 0; i < len; i++) {
//       if (i == 0) {
//         res += (++c);
//       } else {
//         int j = i;
//         for(; j < len && ratings[j] > ratings[j-1]; j++) {
//           res += (++c);
//         }
//         if(j == len) {
//           return res;
//         } else if (ratings[j] == ratings[j-1]) {
//           res += 1;
//           c = 1;
//           i = j;
//           continue;
//         } else {
//           int k = j;
//           c = c == 0 ? 1 : c - 1;
//           for(; k < len && ratings[k] < ratings[k-1]; k++) {
//             res += (c--);
//           }
//           c += 1;
//           int diff = 1 - c;
//           if (diff >= 0) {
//             res += (k - j + 1) * diff;
//           } else {
//             res += (k - j) * diff;
//           }
//           cout << res << " " << diff << " " << c << endl;
//           c = 1;
//           i = k - 1;
//         }
//       }
//     }
//     return res;
//   }
// };
class Solution {
public:
  int candy(vector<int>& ratings) {
    int len = ratings.size();
    if (len == 0) return 0;
    int res = 1;
    int pre = 1;
    int j = 0;
    int h = 1;
    for(int i = 1; i < len; i++) {
      if (ratings[i] == ratings[i-1]) {
        pre = 1;
        j = i;
        h = 1;
      } else if (ratings[i] > ratings[i-1]) {
        pre = pre + 1;
        j = i;
        h = pre;
      } else {
        pre = 1;
        res += (i - j - 1);
        if (i - j + 1 > h) {
          h = i - j + 1;
          res++;
        }
      }
      res += pre;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> vs = {4, 2, 1, 1, 2};
  cout << s.candy(vs);
}
