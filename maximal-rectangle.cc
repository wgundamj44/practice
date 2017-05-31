#include<vector>
#include<stack>
#include<iostream>
using namespace std;

// class Solution {
// public:
//   int maximalRectangle(vector<vector<char>>& matrix) {
//     int h = matrix.size();
//     if (h == 0) return 0;
//     int w = matrix[0].size();
//     vector<int> pre = vector<int>(w, 0);
//     int res = 0;
//     for(int i = 0; i < h; i++) {
//       for(int j = 0; j < w; j++) {
//         if (matrix[i][j] == '1') {
//           pre[j] = pre[j] != 0 ? pre[j] + 1 : 1;
//         } else {
//           pre[j] = 0;
//         }
//       }
//       int r = findMax(pre);
//       if (r > res) res =r;
//     }
//     return res;
//   }

//   int findMax(vector<int>& vs) {
//     vector<int> row = {0};
//     row.insert(row.end(), vs.begin(), vs.end());
//     row.push_back(0);
//     stack<pair<int, int>> s;
//     int res = 0;
//     for(int i = 0; i < row.size(); i++) {
//       int r=  row[i];
//       if (s.empty()) {
//         s.push({i, r});
//       } else {
//         pair<int, int> top = s.top();
//         if (r >= top.second) {
//           s.push({i, r});
//         } else {
//           while(top.second > r) {
//             s.pop();
//             int tmp = top.second * (i - 1 - s.top().first);
//             if (tmp > res) res = tmp;
//             top = s.top();
//           }
//           s.push({i, r});
//         }
//       }
//     }
//     return res;
//   }
// };

class Solution {
  //check: fast
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int h = matrix.size();
    if (h == 0) return 0;
    int w = matrix[0].size();
    if (w == 0) return 0;
    vector<int> heights = vector<int>(w + 1, 0);
    int res = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0 ; j < w; j++) {
        char c = matrix[i][j];
        if (i == 0) {
          heights[j] = c == '1' ? 1 : 0;
        } else {
          if (c == '0') heights[j] = 0;
          else heights[j] = heights[j] + 1;
        }
      }
      stack<int> stk;
      int maxArea = 0;
      heights[w] = -1;
      for(int j = 0; j <= w; j++) {
        if (stk.empty()) {
          stk.push(j);
          continue;
        }
        if (heights[j] >= heights[stk.top()]) {
          stk.push(j);
        } else {
          while(!stk.empty() && heights[stk.top()] >= heights[j]) {
            int height = heights[stk.top()];
            stk.pop();
            int left = stk.empty() ? 0 : stk.top() + 1;
            int area = height * (j - 1 - left + 1);
            if (area > maxArea) maxArea = area;
          }
          stk.push(j);
        }
      }
      if (maxArea > res) res = maxArea;
    }
    
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<char>> input  = {{'1', '0'}, {'1', '1'}};
  cout << s.maximalRectangle(input);
}
