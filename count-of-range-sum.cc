class Solution {
public:
  //check: prefix tree
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    return solve(nums, 0, nums.size() - 1, lower, upper);
  }

  int solve(vector<int>& nums, int b, int e, int lower, int upper) {
    if (b > e) return 0;
    if (b == e) {
      return nums[b] >= lower && nums[b] <= upper ? 1 : 0;
    }
    int m = b + (e - b) / 2;
    int count = 0;
    vector<int> arr;
    for(int i = m; i >= b; i--) {
      count += nums[i];
      arr.push_back(count);
    }
    sort(arr.begin(), arr.end());
    int res = 0;
    long tmp = 0;
    for(int j = m + 1; j <= e; j++) {
      tmp += nums[j];
      long l = lower - tmp, u = upper - tmp;
      int index_l = search_l(arr, l);
      int index_u = search_u(arr, u);
      if (index_l >= 0 && index_u >= 0 && index_l <= index_u) {
        res += (index_u - index_l + 1);
      }
    }
    return res + solve(nums, b, m, lower, upper) + solve(nums, m + 1, e, lower, upper);
  }

  int search_l(vector<int>& vs, long l) {
    int b = 0,  e= vs.size() - 1;
    while(b <= e) {
      int m = b + (e - b) / 2;
      if (vs[m] >= l) {
        e = m - 1;
      } else if (vs[m] < l) {
        b = m + 1;
      }
    }
    if (e == -1) return b;
    if (b == vs.size()) return -1;
    return b;
  }

  int search_u(vector<int>& vs, long u) {
    int b = 0, e = vs.size() - 1;
    while(b <= e) {
      int m = b + (e - b) / 2;
      if (vs[m] <= u) {
        b = m + 1;
      } else {
        e = m - 1;
      }
    }
    if (b == vs.size()) return vs.size() - 1;
    if (e == -1) return - 1;
    return e;
  }
};
