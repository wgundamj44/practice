#include<vector>
#include<set>
#include<iostream>
using namespace std;
class Solution {
  //check: use prefix
public:
  int findMaximumXOR(vector<int>& nums) {
    int max = 0, marsk = 0;
    for(int i = 31; i >= 0; i--) {
      set<int> s;
      marsk = marsk | (1 << i);
      for(int n : nums) {
        s.insert(n & marsk);
      }
      int tmp = max | (1 << i);
      for(int prefix : s) {
        if (s.find(tmp ^ prefix) != s.end()) {
          cout << i << " " << prefix << " " << marsk << endl;
          max = tmp;
          break;
        }
      }
    }
    return max;
  }
};

int main() {
  Solution s;
  vector<int> nums = {3, 5, 10, 25, 2, 8};
  cout << s.findMaximumXOR(nums) << endl;
}
