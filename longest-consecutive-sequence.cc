#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Solution {
  //check: good!
public:
  int longestConsecutive(vector<int>& nums) {
    map<int, int> m;
    int ret = 0;
    for(int n : nums) {
      if (m.find(n) != m.end()) {
        continue;
      }
      if (m.find(n - 1) != m.end()) {
        int pre = m[n-1];
        m[n - pre] = pre + 1;
        m[n] = pre + 1;
      } else {
        m[n] = 1;
      }
      if (m[n] > ret) {
        ret = m[n];
      }
      if (m.find(n + 1) != m.end()) {
        int pre = m[n+1];
        m[n + pre] = pre + m[n];
        m[n - m[n] +1] = pre + m[n];
        if (m[n + pre] > ret) {
          ret = m[n+pre];
        }
      }
    }
    return ret;
  }
};

int main() {
Solution s;
vector<int> nums = {-7,-1,3,-9,-4,7,-3,2,4,9,4,-9,8,-7,5,-1,-7};
cout << s.longestConsecutive(nums) << endl;
}



// class Solution {
// public:
//   int longestConsecutive(vector<int>& nums) {
//     map<int, int> res;
//     for(auto i : nums) {
//       int left = false, right = false;
//       if (res.find(i) != res.end()) {
//         continue;
//       }
//       if (res.find(i-1) != res.end()) {
//         left = true;
//       }
//       if (res.find(i+1) != res.end()) {
//         right = true;
//       }
//       if (left && right) {
//         int leftIndex = res[i-1];
//         int rightIndex = res[i+1];
//         cout << leftIndex << " " << i << " " << rightIndex << endl;
//         res[leftIndex] = rightIndex;
//         res[rightIndex] = leftIndex;
//         for(int j = leftIndex + 1; j < rightIndex;j++) {
//           res.erase(j);
//         }
//       } else if (left) {
//         int leftIndex = res[i-1];
//         res[leftIndex] = i;
//         res[i] = leftIndex;
//         for(int j = leftIndex + 1; j < i;j++) {
//           res.erase(j);
//         }
//       } else if (right) {
//         int rightIndex = res[i+1];
//         res[rightIndex] = i;
//         res[i] = rightIndex;
//         for(int j = i + 1; j < rightIndex;j++) {
//           res.erase(j);
//         }
//       } else {
//         res[i] = i;
//       }
//     }
//     int ret = 0;
//     for(auto entry: res) {
//       cout << entry.first << " " << entry.second << endl;
//       if (abs(entry.second - entry.first) + 1 > ret) {
//         ret = abs(entry.second - entry.first) + 1;
//       }
//     }
//     return ret;
//   }
// };
