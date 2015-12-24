#include<vector>
using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    return bSearch(nums, 0, nums.size() - 1, target) != -1;
  }

  int bSearch(vector<int>& nums, int start, int end, int target) {
    if (start > end) return -1;
    int mid = (int)(start + end) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] == nums[start]) {
      return bSearch(nums, start + 1, end, target);
    } else if (nums[mid] > nums[start]) {
      if (target >= nums[start] && target < nums[mid]) {
	return bSearch(nums, start, mid - 1, target);
      } else {
	return bSearch(nums, mid + 1, end, target);
      }
    } else {
      if (target <= nums[end] && target >= nums[mid]) {
	return bSearch(nums, mid + 1, end, target);
      } else {
	return bSearch(nums, start, mid - 1, target);
      }
    }
    return -1;
  }
};
