#include "TreeNode.h"
#include<algorithm>
using namespace std;

// class Solution {
// public:
//   //check: BFS -> DFS
//   vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
//     map<string, vector<string>> neighbors;
//     wordList.insert(beginWord);
//     wordList.insert(endWord);
//     vector<vector<string>> res;
//     vector<string> tmp;
//     set<string> seen;
//     map<string, set<string>> pre;
//     seen.insert(beginWord);
//     BFS({beginWord}, endWord, wordList, pre, seen);
//     tmp.push_back(endWord);
//     DFS(endWord, beginWord, res, tmp, pre);

//     return res;
//   }
//   void BFS(set<string> last, string e, unordered_set<string> &wordList, map<string, set<string>>& pre, set<string>& seen) {
//     set<string> tmp;
//     bool done = false;
//     for(string b : last) {
//       for(string next: getNeighbors(b, wordList)) {
//         if (seen.find(next) != seen.end()) continue;
//         if (next == e) {
//           done = true;
//         }
//         tmp.insert(next);
//         pre[next].insert(b);
//       }
//     }
//     if (tmp.size() == 0) return;
//     for(string s : tmp) {
//       seen.insert(s);
//     }
//     if (!done) {
//       BFS(tmp, e, wordList, pre, seen);
//     }
//   }

//   void DFS(string begin, string end, vector<vector<string>>& res, vector<string>& tmp, map<string, set<string>>& pre) {
//     if (begin == end) {
//       res.push_back(tmp);
//       return;
//     }
//     for(string p: pre[begin]) {
//       tmp.push_back(p);
//       DFS(p, end, res, tmp, pre);
//       tmp.pop_back();
//     }
//   }
//   vector<string> getNeighbors(string s1, unordered_set<string>& words) {
//     vector<string> ret;
//     for(int i = 0; i < s1.length(); i++) {
//       for(char c = 'a'; c <= 'z'; c++) {
//         char t = s1[i];
//         if (t == c) continue;
//         s1[i] = c;
//         if (words.find(s1) != words.end()) ret.push_back(s1);
//         s1[i] = t;
//       }
//     }
//     return ret;
//   }
// };

typedef map<string, set<string>> Con;
typedef set<string> Level;
class Solution {
public:
  //check: two direction BFS
  vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    Con pre, next;
    wordList.insert(beginWord);
    wordList.insert(endWord);
    set<string> forward = {beginWord}, backward = {endWord}, seen = {beginWord, endWord};
    return BFS(forward, backward, pre, next, true, wordList, seen);
  }

  vector<vector<string>> BFS(Level& forward, Level& backward, Con& pre, Con& next, bool isForward, unordered_set<string>& words, set<string>& seen) {
    vector<vector<string>> res;
    if (isForward) {
      Level level;
      set<string> inter;
      for(string s : forward) {
        for(string n : getNeighbors(s, words)) {
          if (backward.find(n) != backward.end()) {
            inter.insert(n);
          } else {
            if (seen.find(n) != seen.end()) continue;
          }
          level.insert(n);
          pre[n].insert(s);
        }
      }
      if (level.size() == 0) return res;
      seen.insert(level.begin(), level.end());
      if (inter.size() > 0) {
        return generate_path(inter, pre, next);
      } else {
        return BFS(level, backward, pre, next, level.size() <= backward.size(), words, seen);
      }
    } else {
      Level level;
      set<string> inter;
      for(string s : backward) {
        for(string n : getNeighbors(s, words)) {
          if (forward.find(n) != forward.end()) {
            inter.insert(n);
          } else {
            if (seen.find(n) != seen.end()) continue;
          }
          level.insert(n);
          next[n].insert(s);
        }
      }
      if (level.size() == 0) return res;
      seen.insert(level.begin(), level.end());
      if (inter.size() > 0) {
        return generate_path(inter, pre, next);
      } else {
        return BFS(forward, level, pre, next, level.size() <= backward.size(), words, seen);
      }
    }
  }

  vector<vector<string>> generate_path(Level& inter, Con& pre, Con& next) {
    vector<vector<string>> res;
    for(auto s : inter) {
      vector<string> tmp;
      vector<vector<string>> fpath, bpath;
      get_path(s, pre, fpath, tmp);
      tmp.push_back(s);
      get_path(s, next, bpath, tmp);

      for(auto f : fpath) {
        for(auto b : bpath) {
          vector<string> t = f;
          reverse(t.begin(), t.end());
          t.insert(t.end(), b.begin(), b.end());
          res.push_back(t);
        }
      }
    }

    return res;
  }

  void get_path(string s, Con& con, vector<vector<string>>& res, vector<string>& tmp) {
    if (con.find(s) == con.end()) {
      res.push_back(tmp);
      return;
    }
    for(string n : con[s]) {
      tmp.push_back(n);
      get_path(n, con, res, tmp);
      tmp.pop_back();
    }
  }

  set<string> intersect(set<string>& s1, set<string>& s2) {
    set<string> res;
    for(auto s : s1) {
      if (s2.find(s) != s2.end()) {
        res.insert(s);
      }
    }
    return res;
  }

  vector<string> getNeighbors(string s1, unordered_set<string>& words) {
    vector<string> ret;
    for(int i = 0; i < s1.length(); i++) {
      for(char c = 'a'; c <= 'z'; c++) {
        char t = s1[i];
        if (t == c) continue;
        s1[i] = c;
        if (words.find(s1) != words.end()) ret.push_back(s1);
        s1[i] = t;
      }
    }
    return ret;
  }
};


int main() {
  Solution s;
  unordered_set<string> all = {"hot","dot","dog","lot","log"};

  for (auto v : s.findLadders("hit", "cog", all)) {
    for (auto t: v) {
      cout << t << " ";
    }
    cout << endl;
  }
}

    // for(auto s : inter) {
    //   cout << s << " ";
    //   for(auto t : pre[s]) {
    //     cout << t << " ";
    //   }
    //   cout << endl;
    // }


    // for(auto b : bpath) {
    //   for(auto s: b) {
    //     cout << s << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
