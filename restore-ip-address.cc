#include<vector>
#include<string>
using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<int> index;
    solve(s, 1, 0, index, res);

    return res;
  }

  void solve(string s, int n, int i, vector<int>& index, vector<string>& res) {
    int len = s.length();
    int ui = i + 2 < len ? i + 2 : len - 1;
    for(int j = i; j <= ui; j++) {
      string sub = s.substr(i, j - i + 1);
      if (j - i + 1 > 1 && sub[0] == '0') continue;
      if (stoi(sub, nullptr) <= 255) {
	index.push_back(j);
	if (n == 4) {
	  if (j == len -1) {
	    string r = "";
	    for(int k = 0; k < index.size(); k++) {
	      if (k == 0) {
		r = s.substr(0, index[k] + 1);
	      } else {
		r += ("." + s.substr(index[k-1] + 1, index[k] - index[k-1]));
	      }
	    }
	    res.push_back(r);
	  }
	} else{
	  solve(s, n + 1, j + 1, index, res);
	}
	index.pop_back();
      }
    }
  }
};
