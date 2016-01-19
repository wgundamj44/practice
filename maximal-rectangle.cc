#include<vector>
using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int h = matrix.size();
    if (h == 0) {
      return 0;
    }
    int w = matrix[0].size();
    int maxSize = 0;
    vector<vector<int>> sol;
    for(int i = 0; i < h; i++) {
      vector<vector<int>> row;
      for(int j = 0; j < w; j++) {
	if (matrix[i][j] == 0) {
	  continue;
	} else {
	  int e = j;
	  while(e < w && matrix[i][e] == 1) {
	    e++;
	  }
	  if (e >= w) {
	    e = w - 1;
	  }
	  row.push_back({j, e});
	}
      }
    }
  }
};
