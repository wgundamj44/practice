#include<vector>
#include<string>
using namespace std;

// class Solution {
// public:
//   vector<string> restoreIpAddresses(string s) {
//     vector<string> res;
//     vector<int> index;
//     solve(s, 1, 0, index, res);

//     return res;
//   }

//   void solve(string s, int n, int i, vector<int>& index, vector<string>& res) {
//     int len = s.length();
//     int ui = i + 2 < len ? i + 2 : len - 1;
//     for(int j = i; j <= ui; j++) {
//       string sub = s.substr(i, j - i + 1);
//       if (j - i + 1 > 1 && sub[0] == '0') continue;
//       if (stoi(sub, nullptr) <= 255) {
// 	index.push_back(j);
// 	if (n == 4) {
// 	  if (j == len -1) {
// 	    string r = "";
// 	    for(int k = 0; k < index.size(); k++) {
// 	      if (k == 0) {
// 		r = s.substr(0, index[k] + 1);
// 	      } else {
// 		r += ("." + s.substr(index[k-1] + 1, index[k] - index[k-1]));
// 	      }
// 	    }
// 	    res.push_back(r);
// 	  }
// 	} else{
// 	  solve(s, n + 1, j + 1, index, res);
// 	}
// 	index.pop_back();
//       }
//     }
//   }
// };

class Solution {
public:
  //check
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    DFS(s, 0, 1, "", res);
    return res;
  }

  void DFS(string s, int i, int step, string tmp, vector<string>& res) {
    int len = s.length();
    if (step == 4) {
      int r = len - i;
      if (r <= 3 && (r == 1 || (r > 1 && s[i] != '0'))) {
        string sub = s.substr(i);
        if (stoi(sub) > 255) return;
        tmp = tmp + "." + sub;
        res.push_back(tmp);
      }
      return;
    }
    for(int j = 1; j <= 3 && i + j <= len; j++) {
      if (j > 1 && s[i] == '0') return;
      string sub = s.substr(i, j);
      if (stoi(sub) > 255) continue;
      string next;
      if (step == 1) {
        next = sub;
      } else {
        next = tmp + "." + sub;
      }
      DFS(s, i + j, step + 1, next, res);
    }
  }
};
