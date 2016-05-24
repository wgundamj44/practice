class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return generate(nums, 0, nums.size() - 1);
  }

  TreeNode* generate(vector<int>& nums, int b, int e) {
    if (b > e) return nullptr;
    int m = b + (e - b) / 2;
    TreeNode* root = new TreeNode(nums[m]);
    root->left = generate(nums, b, m- 1);
    root->right = generate(nums, m + 1, e);
    return root;
  }
};
