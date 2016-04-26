class NumArray {
  vector<int> _nums;
public:
  NumArray(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
      if (i == 0) _nums.push_back(nums[i]);
      else _nums.push_back(_nums[i-1] + nums[i]);
    }
  }

  int sumRange(int i, int j) {
    return _nums[j] - (i == 0 ? 0 : _nums[i-1]);
  }
};
