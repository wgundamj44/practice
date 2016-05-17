class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<int>> ends = vector<vector<int>>(s.length(), vector<int>());
    for(int i = 0; i < s.length(); i++) {
      for(int j = i; j < s.length(); j++) {
        if (isPalindrome(s, i, j)) {
          ends[i].push_back(j);
        }
      }
    }
    vector<vector<string>> res;
    vector<string> sub
    collect(s, ends, res, sub, 0);
    return res;
  }
  void collect(string s, vector<vector<int>>& ends, vector<vector<string>>& res, vector<string>& sub, int i) {
    if (i > s.length()) {
      res.push_back(sub);
      return;
    }
    for(int j : ends[i]) {
      string str = s.substr(i, j -i + 1);
      sub.push_back(str);
      collect(s, ends, res, sub, j + 1);
      sub.pop_back();
    }
  }
  bool isPalindrome(string s, int i, int j) {
    while(i <= j) {
      if (s[i] != s[j]) return false;
      i++;
      j--;
    }
    return true;
  }
};
