class Solution {
public:
  //check
  vector<string> removeInvalidParentheses(string s) {
    int left = 0, right = 0;
    for(int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        left++;
      } else if (s[i] == ')') {
        if (left > 0) left--;
        else right++;
      }
    }
    set<string> res;
    remove(s, left, right, 0, res);
    return vector<string>(res.begin(), res.end());
  }
  bool valid(string s) {
    stack<char> stk;
    for(char c: s) {
      if (c == '(') stk.push(c);
      else if (c == ')') {
        if (stk.empty()) return false;
        stk.pop();
      }
    }
    return stk.empty();
  }

  void remove(string s, int left, int right, int i, set<string>& res) {
    if (i == s.length()) {
      if (left ==0 && right ==0 && valid(s)) res.insert(s);
      return;
    } else if (s[i] == '(') {
      if (left > 0) {
        remove(s.substr(0, i) + s.substr(i+1), left - 1, right, i, res);
      }
      remove(s, left, right, i + 1, res);
    } else if (s[i] == ')') {
      if (right >0) {
        remove(s.substr(0, i) + s.substr(i+1), left, right - 1, i, res);
      }
      remove(s, left, right, i + 1, res);
    } else {
      remove(s, left, right, i + 1, res);
    }
  }
};
