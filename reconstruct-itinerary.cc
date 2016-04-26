class Solution {
public:
  //check
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    map<string, vector<string>> con;
    for(auto p : tickets) {
      if (con.find(p.first) == con.end()) {
        con[p.first] = { p.second };
      } else {
        con[p.first].push_back(p.second);
      }
    }
    for(auto it = con.begin(); it != con.end(); it++) {
      sort(it->second.begin(), it->second.end());
    }
    string s = "JFK";
    vector<string> path = { s} ;
    set<string> seen;
    DFS(s, con, path, seen, tickets.size() + 1);
    return path;
  }

  bool DFS(string s, map<string, vector<string>>& con, vector<string>& path, set<string>& seen, int count) {
    for(int i = 0 ; i < con[s].size(); i++) {
      string n = con[s][i];
      con[s].erase(con[s].begin() + i);
      path.push_back(n);
      cout << count << " " << path.size() << endl;
      if (count == path.size()) return true;
      if (DFS(n, con, path, seen, count)) return true;
      path.pop_back();
      con[s].insert(con[s].begin() + i, n);
    }
    return false;
  }
};
