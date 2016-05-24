#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  //check
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) return false;
    vector<vector<bool>> res(s1.length() + 1, vector<bool>(s2.length() + 1, false));
    for(int i = 0; i <= s1.length(); i++) {
      for(int j = 0; j <= s2.length(); j++) {
        if (i == 0) {
          if (j == 0) res[i][j] = true;
          else {
            if (s2[j-1] != s3[j-1]) break;
            else res[i][j] = true;
          }
        } else {
          if (j == 0) res[i][j] = (s1[i-1] == s3[i-1]) && res[i-1][j];
          else {
            if (s1[i-1] == s3[i + j - 1]) {
              res[i][j] = res[i-1][j];
            }
            if (s2[j-1] == s3[i + j - 1]) {
              res[i][j] = res[i][j] || res[i][j-1];
            }
          }
        }
      }
    }
    return res[s1.length()][s2.length()];
  }
};


int main() {
  //  string s1 = "bbbcc", s2 = "bbaccbbbabcacc", s3 = "bbbbacbcccbcbabbacc";
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
  Solution *s = new Solution();
  cout << s->isInterleave(s1, s2, s3) << endl;
}
