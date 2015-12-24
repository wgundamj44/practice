#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& height) {
    int maxSize = 0;
    stack<int> s;
    height.push_back(0);
    // -1 becase in the case that height[i] is the minimum so far
    // we need to count from 0 (s.top() + 1)
    s.push(-1);
    for(int i = 0; i < height.size(); i++) {
      while(true) {
	int top = s.top();
	if (s.size() != 1 && height[top] > height[i]) {
	  s.pop();
	  // left limit is the new top + 1
	  // right limit is i - 1
	  int b = s.top() + 1, e = i - 1;
	  int tmp = (e - b + 1) * height[top];
	  if (tmp > maxSize) {
	    maxSize = tmp;
	  }
	} else {
	  s.push(i);
	  break;
	}
      }
    }
    return maxSize;
  }
};
