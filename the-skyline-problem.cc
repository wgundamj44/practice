#include<vector>
#include<map>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
  //check: Divide and conquer
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    if (buildings.size() == 0) return vector<pair<int, int>>();
    if (buildings.size() == 1) {
      return {{buildings[0][0], buildings[0][2]}, {buildings[0][1], 0}};
    }
    vector<pair<int, int>> res;
    int len = buildings.size();
    vector<vector<int>> left = vector<vector<int>>(buildings.begin(), buildings.begin() + len / 2);
    vector<vector<int>> right = vector<vector<int>>(buildings.begin() + len / 2, buildings.end());
    auto lines1 = getSkyline(left);
    auto lines2 = getSkyline(right);
    res = merge(lines1, lines2);

    return res;
  }

  void append(vector<pair<int, int>>& res, pair<int, int> v) {
    int h = v.second;
    if (res.size() > 0 && res.back().second == h) {
    } else if (res.size() > 0 && res.back().first == v.first) {
      res.rbegin()->second = max(h, res.rbegin()->second);
    } else {
      res.push_back(v);
    }
  }

  vector<pair<int, int>> merge(vector<pair<int, int>> v1, vector<pair<int, int>> v2) {
    auto it1 = v1.begin(), it2 = v2.begin();
    vector<pair<int, int>> res;
    int h1 = 0, h2 = 0;
    while(it1 != v1.end() && it2 != v2.end()) {
      if (it1->first < it2->first) {
        h1 = it1->second;
        int h = max(h1, h2);
        append(res, {it1->first, h});
        it1++;
      } else {
        // here is an exception..
        if (it1->first == it2->first && it1->second == it2->second) {
          append(res, *it2);
          it1++;
          it2++;
          continue;
        }
        h2 = it2->second;
        int h = max(h1, h2);
        append(res, {it2->first, h});
        it2++;
      }
    }
    while(it1 != v1.end()) {
      append(res, *it1);
      it1++;
    }
    while(it2 != v2.end()) {
      append(res, *it2);
      it2++;
    }
    return res;
  }
};

class Solution2 {
public:
  //multi set
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    multiset<int> heights;
    vector<pair<int, int>> res, lines;
    for(auto b : buildings) {
      lines.push_back({b[0], -1 * b[2]});
      lines.push_back({b[1], b[2]});
    }
    sort(lines.begin(), lines.end());
    for(auto line: lines) {
      if (line.second < 0) {
        if (heights.size() == 0 || *heights.rbegin() < -1 * line.second) {
          if (res.size() == 0 || res.back().second != -1  * line.second) {
            res.push_back({line.first, -1 * line.second});
          }
        }
        heights.insert(-1 * line.second);
      } else {
        if (*heights.rbegin() == line.second) {
          auto it = heights.end();
          heights.erase(--it);
          int h = heights.size() == 0 ? 0 : *heights.rbegin();
          if (res.size() == 0 || res.back().second != h) {
            res.push_back({line.first, h});
          }
        } else {
          auto it = heights.find(line.second);
          heights.erase(it);
        }
      }
    }
    return res;
  }
};

class Solution3 {
public:
  //segement tree
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  }
}

int main() {
  vector<vector<int>> buildings= {{10, 17, 25}, {12, 20, 14}};
  //vector<vector<int>> buildings= {{1, 2, 1}, {1, 2, 2}};
  Solution2 s;
  for(auto v : s.getSkyline(buildings)) {
    cout << v.first << " " << v.second << endl;
  }
}
