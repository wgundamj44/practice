#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    if (s1.size() == 0) return s2 == s3;
    if (s2.size() == 0) return s1 == s3;

    vector<vector<bool>> res(s1.size() + 1, vector<bool>(s2.size() + 1, false));
    for(int i = s1.size() - 1; i >=0; i--) {
      res[i][s2.size()] = (s1[i] == s3[s2.size() + i]);
    }
    for(int i = s2.size() - 1; i >= 0; i--) {
      res[s1.size()][i] = (s2[i] == s3[s1.size() + i]);
    }
    for(int i = s1.size() - 1; i >= 0; i--) {
      for(int j = s2.size() - 1; j >= 0; j--) {
	res[i][j] = (s1[i] == s3[j + i] && res[i+1][j]) || (s2[j] == s3[j + i] && res[i][j+1]);
	cout << i << " " << j << " " << res[i][j] << endl;
      }
    }
    return res[0][0];
  }

};


int main() {
  string s1 = "bbbcc", s2 = "bbaccbbbabcacc", s3 = "bbbbacbcccbcbabbacc";
  Solution *s = new Solution();
  cout << s->isInterleave(s1, s2, s3) << endl;
}
