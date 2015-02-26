class Solution {
public:
    void rotate(int nums[], int n, int k) {
        rotateSub(nums, 0, n - 1, k, true);
    }
    
    void rotateSub(int nums[], int s, int e, int k, bool right) {
        int len = e - s + 1;
        
        if (k >= len) k = k % len;
        if (s >= e || k == 0) {
            return;
        }
        
        if (k > len - k) {
            right = !right;
            k = len - k;
        }
        
        for(int i = s; i < s + k; i++) {
            int j = e - (k - 1) +  (i - s);
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        if (right) {
            rotateSub(nums, s + k, e, k, right);
        } else {
            rotateSub(nums, s, e - k, k, right);
        }
    }
};
