class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    ListNode* pre = nullptr, *p = head, *p1 = head;
    while(p1->next && p1->next->next) {
      p1 = p1->next->next;
      if (!pre) {
        pre = head;
      } else {
        pre = pre->next;
      }
      p = p->next;
    }
    TreeNode* root = new TreeNode(p->val);
    if (pre) {
      pre->next = nullptr;
      root->left = sortedListToBST(head);
      pre->next = p;
    } else {
      root->left = nullptr;
    }
    root->right = sortedListToBST(p->next);
    return root;
  }
};
