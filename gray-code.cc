#include<vector>
#include<map>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
  //check
  vector<int> grayCode(int n) {
    if (n == 0) return {0};
    auto ret = grayCode(n - 1);
    auto res = ret;
    
    for(auto it = ret.rbegin(); it != ret.rend(); it++) {
      res.push_back((1 << (n-1)) ^ *it);
    }
    return res;
  }

  // a bad idea
  bool DFS(int v, vector<int>& res, map<int, bool>& m, int n) {
    for(int i = 0; i < n; i++) {
      int tmp = v ^ (1 << i);
      if (m.find(tmp) == m.end()) {
	m[tmp] = true;
	res.push_back(tmp);
	if (res.size() == n) {
	  return true;
	}
	if (!DFS(tmp, res, m, n)) {
	  m.erase(tmp);
	  res.pop_back();
	} else {
	  return true;
	}
      }
    }
    return false;
  }
};

int main() {
  cout << (3 ^ 1) << endl;
  cout << (3 ^ (1 << 1)) << endl;
}
