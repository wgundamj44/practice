#include<vector>
#include<queue>
using namespace std;

//check: notice that lambda's capture should by reference
//check: priority queue
class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto cmp = [&matrix](const pair<int,int> &p1, const pair<int, int> &p2) {
      return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    for(int i = 0; i < matrix[0].size(); i++) {
      q.push({0, i});
    }
    int count = 0;
    while(true) {
      auto p = q.top();
      count++;
      q.pop();
      if (count == k) {
        return matrix[p.first][p.second];
      }
      if(p.first < matrix.size() - 1) {
        q.push({p.first + 1, p.second});
      }
    }
  }
};
