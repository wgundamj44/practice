class Solution {
  //check: DP
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    vector<unordered_map<int,int>> m(A.size());
    if (A.size() < 3) return 0;
    int ret = 0;
    for(int i = 1; i < A.size(); i++) {
      for(int j = 0; j < i; j++) {
        long d = (long)A[i] - (long)A[j];
        if (d < INT_MIN || d > INT_MAX) continue;
        m[i][d]++;
        if (m[j].find(d) != m[j].end()) {
          m[i][d] += (m[j][d]);
          ret += (m[j][d]);
        }
      }
    }
    return ret;
  }
};
