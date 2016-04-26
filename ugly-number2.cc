class Solution {
public:
  int nthUglyNumber(int n) {
    list<int> L[3] = {list<int>(), list<int>(), list<int>()};
    set<int> allRes;
    if (n == 1) return 1;
    L[0].push_back(1);
    allRes.insert(1);
    int res;
    while(allRes.size() != n) {
      int m;
      int tmp = INT_MAX;
      for(int j = 0; j < 3; j++) {
        if (L[j].empty()) continue;
        if (j == 0) {
          if (L[j].front() * 2 < tmp) {
            tmp = L[j].front() * 2;
            m = j;
          }
        } else if (j == 1) {
          if (L[j].front() * 3 < tmp) {
            tmp = L[j].front() * 3;
            m = j;
          }
        } else {
          if (L[j].front() * 5 < tmp) {
            tmp = L[j].front() * 5;
            m = j;
          }
        }
      }
      int v = L[m].front();
      L[m].pop_front();
      if (m != 2) L[m+1].push_back(v);

      if (allRes.find(tmp) != allRes.end()) continue;
      res = tmp;
      L[0].push_back(res);
      allRes.insert(tmp);
    }
    return res;
  }
};
