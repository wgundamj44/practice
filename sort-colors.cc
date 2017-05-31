// class Solution {
// public:
//     void sortColors(vector<int>& nums) { 
//         int i = 0, len = nums.size();
//         // keep swapping, so that 2s are to the end, and first index of 1s are behind 0.
//         int f1 = -1, f2 = len - 1;
//         while(i <= f2) {
//             if (nums[i] == 0) {
//                 if (f1 != -1 && i > f1) {
//                     swap(nums[f1], nums[i]);
//                     f1++;
//                 } 
//                 i++;
//             }
//             else if (nums[i] == 1) {
//                 if (f1 == -1) {
//                     f1 = i;
//                 }
//                 i++;
//             }
//             else if (nums[i] == 2) {
//                 if (i != f2) {
//                     swap(nums[i], nums[f2]);
//                     f2--;
//                 } else {
//                     break;   
//                 }
//             }
//         }
//     }
// };


class Solution {
  //check
public:
  void sortColors(vector<int>& nums) {
    int b = 0, e = nums.size() - 1;
    int i = 0;
    for(int i = 0; i < nums.size() && i <= e; i++) {
      if (nums[i] == 0) {
        swap(nums[b++], nums[i]);
      } else if (nums[i] == 2) {
        swap(nums[e--], nums[i]);
        i--;
      } else {
        swap(nums[b], nums[i]);
      }
    }
  }
};
