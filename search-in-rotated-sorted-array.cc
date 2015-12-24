#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bSearch(nums, 0, nums.size() - 1, target);
    }
    
    int bSearch(vector<int>& nums, int b, int e, int target) {
        if (b > e) {
            return -1;
        }
        int mid = floor((b + e) / 2);
        if (nums[mid] == target) {
            return mid;
        }
	if (nums[mid] >= nums[b]) {
	  if (target >= nums[b] && target < nums[mid]) {
	    return bSearch(nums, b, mid - 1, target);
	  } else {
	    return bSearch(nums, mid + 1, e, target);
	  }
	} else {
	  if (target > nums[mid] && target <= nums[e]) {
	    return bSearch(nums, mid + 1, e , target);
	  } else {
	    return bSearch(nums, b, mid - 1, target);
	  }
	}
        
        return -1;
    }
};
