class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       return bSearch(0, nums.size() - 1, nums, target);
    }
    
    vector<int> bSearch(int b, int e, vector<int>& nums, int target) {
        if (b > e) {
            return { -1, -1 };
        }
        
        int mid = (b + e) / 2;
        int l, u;
        vector<int> r1, r2;
        if (nums[mid] > target) {
            return bSearch(b, mid - 1, nums, target);
        } else if(nums[mid] < target) {
            return bSearch(mid + 1, e, nums, target);
        } else {
            r1 = bSearch(b, mid - 1, nums, target);
            r2 = bSearch(mid + 1, e, nums, target);
            l = r1[0] == -1 ? mid : r1[0];
            u = r2[1] == -1 ? mid : r2[1];
            return {l, u};
        }
        
        
    }
};