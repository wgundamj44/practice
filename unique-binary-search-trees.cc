#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
  int numTrees(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    vector<int> tmp(n+1, 0);
    tmp[0] = 1;
    tmp[1] = 1;
    tmp[2] = 2;
    for(int i = 3; i <= n; i++) {
      for(int j = 0; j <= i - 1; j++) {
	tmp[i] += (tmp[j] * tmp[i - 1 - j]);
      }
    }
    cout << tmp[3] << endl;
    return tmp[n];
  }
};

int main() {
  Solution *s=  new Solution();
  cout << s->numTrees(4) << endl;
}
