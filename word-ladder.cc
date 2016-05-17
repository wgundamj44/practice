class Solution {
public:
  int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    unordered_set<string> seen;
    map<string, vector<string>> connects;
    for(auto s1 : wordList) {
      for(auto s2 : wordList) {
        if (s1 != s2) {
          if (isConnected(s1, s2)) {
            if (connects.find(s1) == connects.end()) {
              connects[s1] = {s2};
            } else {
              connects[s1].push_back(s2);
            }
          }
        }
      }
    }
    int len = wordList.size();
    DFS(beginWord, endWord, seen, connects, 1, len);

    return len;
  }

  void DFS(string b, string e, unordered_set<string>& seen, map<string,vector<string>> connects, int len, int& minLen) {
    for(auto s: connects[b]) {
      if (seen.find(s) != seen.end()) {
        continue;
      }
      if (s == e) {
        if (len + 1 < minLen) {
          minLen = len + 1;
        }
        return;
      }
      if (len + 1 >= minLen) return;
      seen.insert(s);
      DFS(s, e, seen, connects, len + 1, minLen);
      seen.erase(s);
    }
  }

  bool isConnected(string s1, string s2) {
    int diff = 0;
    for(int i = 0; i < s1.length(); i++) {
      if (s1[i] != s2[i]) {
        diff++;
        if (diff > 1) return false;
      }
    }
    return diff == 1;
  }
};
