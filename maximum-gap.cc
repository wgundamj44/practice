class Solution {
public:
  //check: radix sort
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    radixSort(nums);
    int res = 0;
    for(int i = 1; i < nums.size(); i++) {
      res = max(res, nums[i] - nums[i-1]);
    }
    return res;
  }

  void radixSort(vector<int>& nums) {
    int peek = nums[0];
    for(int i = 0; i < nums.size(); i++) {
      peek = max(peek, nums[i]);
    }
    for(int exp = 1; peek / exp > 0; exp *= 10) {
      countSort(nums, exp);
    }
  }

  void countSort(vector<int>& nums, int exp) {
    vector<int> count(11, 0);
    vector<int> tmp(nums.size(), 0);
    for(int n : nums) {
      int i = (n / exp) % 10;
      count[i+1]++;
    }
    for(int i = 1; i <= 10; i++) {
      count[i] += count[i-1];
    }
    for(int i = 0; i < nums.size(); i++) {
      int d = (nums[i] / exp) % 10;
      tmp[count[d]++] = nums[i];
    }
    for(int i = 0; i < nums.size(); i++) {
      nums[i] = tmp[i];
    }
  }
};
