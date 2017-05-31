class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> vs;
    string res = "";
    k = k - 1;
    for(int i = 1; i <= n; i++) vs.push_back(i);
    while(vs.size() != 0) {
      int d = fact(vs.size() - 1);
      int i = k / d;
      int r = k % d;
      int h = *(vs.begin() + i);
      vs.erase(vs.begin() + i);
      res += to_string(h);
      k = r;
    }
    return res;
  }

  int fact(int n) {
    int res = 1;
    while(n != 0) {
      res *= n--;
    }
    return res;
  }
};
