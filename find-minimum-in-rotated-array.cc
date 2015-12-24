#include<vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    return bSearch(nums, 0, nums.size() - 1);
  }

  int bSearch(vector<int>& nums, int b, int e) {
    int mid = floor((b + e) / 2);
    if (nums[mid] > nums[e]) {
      return bSearch(nums, mid + 1, e);
    } else {
      if (mid == b) {
	return nums[mid];
      } else {
	if (nums[mid] >= nums[b]) {
	  return nums[b];
	} else {
	  return bSearch(nums, b + 1, mid);
	}
      }
    }
  }
};
