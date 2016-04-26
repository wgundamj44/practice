class Solution {
public:
  //check
  int lengthOfLIS(vector<int>& nums) {
    vector<int> tail;
    for(int n : nums) {
      if (tail.size() == 0) {
        tail.push_back(n);
      } else {
        if (n <= tail[0]) {
          tail[0] = n;
        } else if (n > tail.back()) {
          tail.push_back(n);
        } else {
          int b = 0, e = tail.size() - 1;
          while(b < e - 1) {
            int m = b + (e - b) / 2;
            if (tail[m] > n) {
              e = m ;
            } else if (tail[m] < n) {
              b = m;
            } else {
              b = m-1;
              break;
            }
          }
          tail[b+1] = n;
        }
      }
    }
    return tail.size();
  }
};
