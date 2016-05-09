class Solution {
public:
  //check
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> inDegree(numCourses, 0);
    queue<int> q;
    for(auto p : prerequisites) {
      inDegree[p.first]++;
    }
    for(int i = 0; i < inDegree.size(); i++) {
      if (inDegree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
      int pre = q.front();
      q.pop();
      for(auto p : prerequisites) {
        if (pre == p.second) {
          inDegree[p.first]--;
          if (inDegree[p.first] == 0) {
            q.push(p.first);
          }
        }
      }
    }
    for(auto i : inDegree) {
      if (i != 0) return false;
    }
    return true;
  }
};
