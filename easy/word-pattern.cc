class Solution {
public:
  bool wordPattern(string pattern, string str) {
    map<string, char> m;
    map<char, string> m1;
    int n = 0;
    for(int i = 0; i < str.size(); i++) {
      if (str[i] == ' ') continue;
      int j = i;
      for(; j < str.size() && str[j] != ' '; j++);
      string sub = str.substr(i, j - i);
      if (m.find(sub) == m.end()) {
        if (m1.find(pattern[n]) != m1.end()) return false;
        m[sub] = pattern[n];
        m1[pattern[n]] = sub;
      } else {
        if (m[sub] != pattern[n]) return false;
        if (m1[pattern[n]] != sub) return false;
      }
      i = j;
      n++;
    }
    return pattern.size() == n;
  }
};
