#include<list>
#include<iostream>
using namespace std;

class Solution {
public:
  int lastRemaining(int n) {
    list<int> nums;
    for(int i = 1; i <= n; i++) nums.push_back(i);
    while(nums.size() > 1) {
      auto it = nums.begin();
      auto it1 = next(it, 1);
      while(it != nums.end()) {
        nums.erase(it);
        it = next(it1, 1);
        if (it != nums.end() && next(it, 1) != nums.end()) it1 = next(it, 1);
      }
      if (nums.size() == 1) break;
      it = it1;
      it1 = next(it, -1);
      while(true) {
        nums.erase(it);
        if (it1 != nums.begin()) it = next(it1, -1);
        else break;
        if (it != nums.begin()) it1 = next(it, -1);
      }
    }
    return nums.front();
  }
};

int main() {
  Solution s;
  cout << s.lastRemaining(3) << endl;
}
