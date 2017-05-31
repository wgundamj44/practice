class Solution {
public:
  //check: DP
  bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    int len = s1.length();
    vector<vector<vector<bool>>> A = vector<vector<vector<bool>>>(len + 1, vector<vector<bool>>(len, vector<bool>(len, false)));
    for(int i = 1; i <= len; i++) {
      for(int j = 0; j < len; j++) {
        for(int k = 0; k < len; k++) {
          if (j + i > len || k + i > len) continue;
          if (i == 1) {
            A[i][j][k] = s1[j] == s2[k];
          } else {
            for(int z = 1; z < i; z++) {
              A[i][j][k] = A[i][j][k] || (A[z][j][k] && A[i-z][j+z][k+z]);
              A[i][j][k] = A[i][j][k] || (A[z][j][k+i-z] && A[i-z][j+z][k]);
            }
          }
        }
      }
    }

    return A[len][0][0];
  }
};
