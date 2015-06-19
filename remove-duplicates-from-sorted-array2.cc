class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int p = nums[0], d = 1;
        int t = 1;
        for(int i = 1; i < nums.size(); i++) {
           if(nums[i] == p) {
               if(d <= 1) {
                   d++;
                   nums[t] = nums[i];
                   t++;
               }
           } else {
               d = 1;
               p = nums[i];
               nums[t] = nums[i];
               t++;
           }
        }
        return t;
    }
};
