class NumArray {
public:
  //check
  NumArray(vector<int> &nums) {
    tree = vector<int>(nums.size() + 1, 0);
    for(int i = 0;i < nums.size(); i++) {
      update(i, nums[i]);
    }
  }

  void update(int i, int val) {
    int index = i + 1;
    int org = sumRange(i, i);
    int diff = val - org;
    while(index < tree.size()) {
      tree[index] += diff;
      index = index + (index & (-index));
    }
  }

  int sumRange(int i, int j) {
    return treeSum(j) - (i == 0 ? 0 : treeSum(i-1));
  }
private:
  vector<int> tree;
  int treeSum(int i) {
    int index = i + 1;
    int res = 0;
    while(index > 0) {
      res += tree[index];
      index = index - (index & (-index));
    }
    return res;
  }
};
