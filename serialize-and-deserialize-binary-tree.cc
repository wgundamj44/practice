#include "TreeNode.h"
#include<string>
#include<queue>
#include<iostream>
using namespace std;

class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "";
    string res = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      auto node = q.front();
      q.pop();
      string tmp = "";
      if (res == "") {
        tmp = to_string(node->val);
      }
      if (node->left) {
        q.push(node->left);
        tmp += ((tmp == "" ? "" : ",") + to_string(node->left->val));
      } else {
        tmp += (tmp == "" ? "#" : ",#");
      }
      if (node->right) {
        q.push(node->right);
        tmp += ("," + to_string(node->right->val));
      } else {
        tmp += ",#";
      }
      if (res == "") {
        res = tmp;
      } else {
        res += (","  + tmp);
      }
    }
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "") return nullptr;
    int i = 0;
    queue<TreeNode*> q;
    TreeNode* root;
    while(true) {
      TreeNode* pre = nullptr;
      if (!q.empty()) {
        pre = q.front();
        q.pop();
      }
      string sub = nextToken(data, i);
      i++;
      if (sub == "#") {
        pre->left = nullptr;
      } else {
        int val = stoi(sub);
        TreeNode* node = new TreeNode(val);
        if (pre == nullptr) {
          root = node;
          q.push(node);
          continue;
        } else {
          pre->left = node;
          q.push(node);
        }
      }
      sub = nextToken(data, i);
      i++;
      if (sub == "#") {
        pre->right = nullptr;
      } else {
        int val = stoi(sub);
        TreeNode* node = new TreeNode(val);
        pre->right = node;
        q.push(node);
      }
      if (i >= data.length()) break;
    }
    return root;
  }

  string nextToken(string data, int& i) {
    int j = i;
    for(; j < data.length() && data[j] != ','; j++);
    string sub = data.substr(i, j - i);
    cout << i << " " << j << " " << sub << endl;
    i = j;
    return sub;
  }
};

int main() {
  Codec c;
  auto t = new TreeNode(1);
  t->left = new TreeNode(2);
  cout << c.serialize(t) << endl;
  c.deserialize(c.serialize(t));
}
