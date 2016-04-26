class Solution {
public:
  //check
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (n == 1) return {0};
    map<int, set<int>> con;
    for(auto p : edges) {
      if (con.find(p.first) != con.end()) {
        con[p.first].insert(p.second);
      } else {
        con[p.first] = {p.second};
      }
      if (con.find(p.second) != con.end() ) {
        con[p.second].insert(p.first);
      } else {
        con[p.second] = {p.first};
      }
    }
    while(true) {
      queue<int> q;
      for(auto it = con.begin(); it != con.end(); it++) {
        if (it->second.size() <= 1) {
          q.push(it->first);
        }
      }
      if (con.size() <= 2) {
        vector<int> res;
        for(auto it2 = con.begin(); it2 != con.end(); it2++) {
          res.push_back(it2->first);
        }
        return res;
      }
      while(!q.empty()) {
        int i = q.front();
        q.pop();
        int j = *(con[i].begin());
        con[j].erase(i);
        con.erase(i);
      }
    }
  }
};
