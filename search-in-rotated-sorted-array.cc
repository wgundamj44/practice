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
        if (nums[mid] > target) {
            int flg = bSearch(nums, b, mid - 1, target);
            if (flg != -1) return flg;
            if (target <= nums[e]) {
                flg = bSearch(nums, mid + 1, e, target);
                if (flg != -1) return flg;
            }
        } else {
            int flg = bSearch(nums, mid + 1, e, target);
            if (flg != -1) return flg;
            if (target >= nums[b]) {
                flg = bSearch(nums, b, mid - 1, target);
                if (flg != -1) return flg;
            }
        }
        
        return -1;
    }
};