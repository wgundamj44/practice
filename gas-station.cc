class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int i = 0, remain = 0, start = 0;
    map<int, vector<int>> res;
    while(true) {
      if (res.find(i) != res.end() && res[i].size() != 0) {
        auto ires = res[i];
        if (i != start && (ires[0] >= start && ires[0] < i)) {
          return start;
        } else {
          remain += ires[1];
          i = (ires[0] + 1) % len;
          continue;
        }
      }
      int diff = gas[i] - cost[i];
      if (remain + diff < 0) {
        if (res.find(start) != res.end()) return -1;
        if (start != i) {
          res[start] = {(len + i - 1) % len, remain};
        } else {
          res[start] = {};
        }
        i = (i + 1) % len;
        start = i;
        remain = 0;
      } else {
        remain += diff;
        i = (i + 1) % len;
        if (i == start) return i;
      }
    }
  }
};
