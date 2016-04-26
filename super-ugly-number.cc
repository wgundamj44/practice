class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<priority_queue<int, vector<int>, greater<int>>> vs(primes.size());
    int last;
    for(int i = 1; i <= n; i++) {
      int t = 0;
      int res = INT_MAX;
      for(int j = 0; j < vs.size(); j++) {
        if (!vs[j].empty()) {
          if (vs[j].top() * primes[j] < res) {
            res = vs[j].top() * primes[j];
            t = j;
          }
        }
      }
      if (i == 1) {
        res = 1;
        vs[0].push(res);
      } else {
        int tmp = vs[t].top();
        vs[t].pop();
        if (last != res) {
          vs[0].push(res);
        } else {
          i = i - 1;
        }
        if (t < vs.size() - 1) {
          vs[t+1].push(tmp);
        }
      }
      last = res;
      if (i == n) return res;
    }
  }
};
