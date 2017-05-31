class Solution {
public:
  int lengthLongestPath(string input) {
    int res = 0;
    int b = 0;
    vector<int> stk;
    longest(input, b, input.size() - 1, stk, res);
    return res;
  }

  void longest(string& input, int& b, int e, vector<int>& stk, int& res) {
    if (b > e) return;
    int level = 0;
    bool isFile = false;
    if (input[b] != '\t') {

    } else {
      while(input[b] == '\t') {
        level++;
        b++;
      }
    }
    int len = 0, current = 0;
    for(; b <= e && input[b] != '\n'; b++) {
      len++;
      if (input[b] == '.') isFile = true;
    }
    b++;
    if (stk.size() < level + 1) {
      stk.push_back(0);
    }
    if (level == 0) {
      stk[0] = len;
      if (isFile) current = len;
    } else {
      stk[level] = stk[level - 1] + len;
      if (isFile) current = stk[level] + level;
    }
    if (current > res) {
      res = current;
    }
    longest(input, b, e, stk, res);
  }
};
