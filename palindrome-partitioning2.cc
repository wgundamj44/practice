class Solution {
public:
  //check: calculate minCust[i] from i = 0..len
  // also maintains the palindrome ends with s[i]
  int minCut(string s) {
    vector<int> cuts;
    vector<bool> isPalin = vector<bool>(s.length(), false);
    for(int i = 0; i < s.length(); i++) {
      if (i == 0) {
        isPalin[0] = true;
        cuts.push_back(0);
      } else {
        int tmpMinCut = i;
        for(int j = 0; j <= i; j++) {
          if (i == j) {
            isPalin[j] = true;
          } else if (j == i - 1) {
            isPalin[j] = s[i] == s[j];
          } else {
            //isPalin[j+1] is caculated in last iteration, indicating palin info of s[j+1..i-1]
            isPalin[j] = isPalin[j+1] & (s[i] == s[j]); 
          }
          if (isPalin[j]) {
            if (j == 0) {
              tmpMinCut = 0;
            } else {
              if (cuts[j-1] + 1 < tmpMinCut) {
                tmpMinCut = cuts[j-1] + 1;
              }
            }
          }
        }
        cuts.push_back(tmpMinCut);
      }
    }
    return cuts.back();
  }
};
