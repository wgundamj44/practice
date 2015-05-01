class Solution {
public:
    // use nums in place so that: nums[i] == i + 1
    // not nums[i] == i because nums[0] should be 1 ..
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            if (nums[i] < 0) {
                continue;
            } else if (nums[i] == i + 1) {
                continue;
            } else {
                if (nums[i] > len) {
                    nums[i] = -1;
                } else {
                    while(nums[i] > 0 && nums[i] <= len) {
                        int tmp = nums[nums[i] - 1];
                        if (tmp == nums[i]) {
                            break;
                        }
                        nums[nums[i] - 1] = nums[i];
                        nums[i] = tmp;
                    }
                    if (nums[i] > len) {
                        nums[i] = -1;
                    }
                }
            }
        }
        for(int i = 0; i < len; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return len + 1;
    }
};