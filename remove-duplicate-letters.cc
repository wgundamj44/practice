class Solution {
public:
  //check
  string removeDuplicateLetters(string s) {
    vector<int> ps;
    vector<int> vs = vector<int>(26, 0);
    vector<bool> used = vector<bool>(26, false);
    for(int i = 0; i < s.length(); i++) {
      int k = (int)(s[i] - 'a');
      vs[k]++;
    }
    for(int i = 0 ; i < s.length(); i++) {
      int k = (int)(s[i] - 'a');
      if (used[k]) {
        vs[k]--;
        continue;
      }
      for(int j = ps.size() - 1; j >= 0; j--) {
        if (ps[j] > k && vs[ps[j]] > 1) {
          ps.erase(ps.begin() + j);
          vs[ps[j]]--;
          used[ps[j]] = false;
        } else {
          break;
        }
      }
      if (used[k] == false) {
        ps.push_back(k);
        used[k] = true;
      }
    }
    string res = "";
    for(int i : ps) {
      res = res + string(1, (char)(i+'a'));
    }
    return res;
  }
};
