class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        int nearest = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= nearest) {
                nearest = i;
            }
        }
        return nearest == 0;
    }
};
