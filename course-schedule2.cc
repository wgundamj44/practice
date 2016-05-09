class Solution {
public:
  //check
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> ins(numCourses, 0);
    vector<int> res;
    map<int, vector<int>> nexts;
    for(auto pre : prerequisites) {
      ins[pre.first]++;
      if (nexts.find(pre.second) != nexts.end()) {
        nexts[pre.second].push_back(pre.first);
      } else {
        nexts[pre.second] = { pre.first };
      }
    }
    int i;
    queue<int> q;
    for(i = 0; i < ins.size(); i++) {
      if (ins[i] == 0) q.push(i);
    }
    while(!q.empty()) {
      i = q.front();
      q.pop();
      res.push_back(i);
      for(auto n : nexts[i]) {
        ins[n]--;
        if (ins[n] == 0) q.push(n);
      }
    }
    vector<int> empty;
    for(i = 0; i < ins.size(); i++) {
      if (ins[i] != 0) return empty;
    }
    return res;
  }
};
