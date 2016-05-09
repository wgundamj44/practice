#include "TreeNode.h"
using namespace std;

// bad
// class Solution {
// public:
//   //check
//   vector<int> singleNumber(vector<int>& nums) {
//     vector<int> ret;
//     int j = 0;
//     for(int i = 0; i < nums.size(); i++) {
//       if (nums[i] == 0) {
//         swap(nums[j++], nums[i]);
//       }
//     }
//     if (j == 1) {
//       ret.push_back(nums[j-1]);
//     }
//     search(nums, j, nums.size() - 1, ret);
//     return ret;
//   }

//   void search(vector<int>& nums, int b, int e, vector<int>& ret) {
//     if (b > e) return;
//     if (b == e) {
//       ret.push_back(nums[b]);
//       return;
//     }
//     int m = b + (e - b) / 2;
//     swap(nums[b], nums[m]);
//     int i = b + 1, j = b + 1;
//     bool flg = false;
//     int res1 = 0, res2 = 0;
//     int z;
//     for(; i <= e; i++) {
//       if (nums[i] < nums[b]) {
//         res1 = res1 ^ nums[i];
//         swap(nums[j], nums[i]);
//         j++;
//       } else if (nums[i] > nums[b]) {
//         res2 = res2 ^ nums[i];
//       } else {
//         z = j;
//         swap(nums[j], nums[i]);
//         flg = true;
//         j++;
//       }
//     }
//     swap(nums[b], nums[j-1]);
//     if (flg) {
//       if (z == j - 1) {
//         swap(nums[b], nums[j-2]);
//       } else {
//         swap(nums[z], nums[j-2]);
//       }
//       if (res1) {
//         search(nums, b, j - 3, ret);
//       }
//       if (res2) {
//         search(nums, j, e, ret);
//       }
//     } else {
//       ret.push_back(nums[j-1]);
//       if (res1) {
//         search(nums, b, j - 2, ret);
//       }
//       if (res2) {
//         search(nums, j, e, ret);
//       }
//     }
//   }
// };

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int x = 0;
    for(int n : nums) {
      x = x ^ n;
    }
    //find the first bit that two numbers differs
    int bit = x & ~(x-1);
    int res1 = 0, res2 = 0;
    for(int n : nums) {
      if ((n & bit) > 0) {
        res1 = res1 ^ n;
      } else {
        res2 = res2 ^ n;
      }
    }
    return {res1, res2};
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 1, 3, 5, 2};
  for(auto v : s.singleNumber(nums)) {
    cout << v << endl;
  }
}
