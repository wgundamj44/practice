class Solution {
public:
  //check
  vector<string> addOperators(string num, int target) {
    vector<string> ret;
    DFS(num, target, 0, ret, "", 0, 0);

    return ret;
  }

  void DFS(string num, int target, int i, vector<string>& ret, string tmp, long cur, long pre) {
    if (i >= num.length()) {
      if (target == cur) ret.push_back(tmp);
      return;
    }
    for(int j = i; j < num.length(); j++) {
      if (j > i && num[i] == '0') continue;
      string sub = num.substr(i, j - i + 1);
      long value = stol(sub);
      if (i == 0) {
        DFS(num, target, j + 1, ret, sub, value, value);
      } else {
        DFS(num, target, j + 1, ret, tmp + "+" + sub, cur + value, value);
        DFS(num, target, j + 1, ret, tmp + "-" + sub, cur - value, -1 * value);
        DFS(num, target, j + 1, ret, tmp + "*" + sub, cur - pre + pre * value, value * pre);
      }
    }
  }

};
