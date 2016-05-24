class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    TreeLinkNode *nextRoot = nullptr;
    while(root) {
      if (root->left && root->right) {
        root->left->next = root->right;
        if (!nextRoot) nextRoot = root->left;
      }
      if (root->right || root->left) {
        auto p = root->right ? root->right : root->left;
        if (!nextRoot) nextRoot = p;
        auto p1 = root;
        while(p1->next) {
          p1 = p1->next;
          auto next = p1->left ? p1->left : p1->right;
          if (next) {
            p->next = next;
            break;
          }
        }
      }
      if(root->next) {
        root = root->next;
      }
      else {
        root = nextRoot;
        nextRoot = nullptr;
      }
    }
  }
};
