class Solution {
public:
  //check
  int findDuplicate(vector<int>& nums) {
    int b = 1, e= nums.size() - 1;
    while(b < e) {
      int mid = b + (e - b) / 2;
      bool flag = ((e - b) % 2 == 0);
      int c1 = 0, c2 = 0, c3 = 0;
      for(int n : nums) {
        if (flag) {
          if (n >= b && n < mid) {
            c1++;
          } else if (n > mid && n <=e) {
            c2++;
          } else if (n == mid) {
            c3++;
          }
        } else{
          if (n >= b && n <= mid) {
            c1++;
            if (n == mid) c3++;
          } else if (n > mid && n <= e) {
            c2++;
          }
        }
      }
      if (c3 > 1) return mid;
      if (c1 > c2) {
        e = mid - 1;
      } else {
        b = mid + 1;
      }
    }
    return b;
  }
};
