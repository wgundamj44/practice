#include<vector>
#include<set>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        int len = num.size();
        int i = 0;
        while(i < len) {
            int target = -1 * num[i];
            int start = i + 1, end = len - 1;
            while(start < end) {
                if (num[start] + num[end] == target) {
                    vector<int> tmp = {num[i], num[start], num[end]};
                    res.push_back(tmp);
                    int s  = num[start], e = num[end];
                    while(start < end && num[start] == s) start++;
                    while(start < end && num[end] == e) end--;
                } else if (num[start] + num[end] < target) {
                    start++;
                } else {
                    end--;
                }
            }
            while(i < len && num[i] == -1 * target) {
                i++;
            }
        }
        return res;
    }
};


int main() {
  Solution *s = new Solution();
  vector<int> input = {-1, 0, 1, 2, -1, -4};
  auto t = s->threeSum(input);
  for(auto res : t) {
    for(auto v : res) {
      cout << v << " ";
    }
    cout << endl;
  }
}
