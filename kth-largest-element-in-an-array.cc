class Solution {
public:
  //check
  int findKthLargest(vector<int>& nums, int k) {
    return findMedian(nums, 0, nums.size() - 1, nums.size() - k + 1);
  }

  int findMedian(vector<int>& nums, int s, int e, int k) {
    vector<int> medians;
    for(int i = s; i <= e; i += 5) {
      if (i + 5 > e) {
        sort(nums.begin() + i, nums.begin() + e + 1);
        medians.push_back(nums[i + (e - i) / 2]);
      } else {
        sort(nums.begin() + i, nums.begin() + i + 5);
        medians.push_back(nums[i + 2]);
      }
    }
    int m = medians.size() == 1 ? medians[0] : findMedian(medians, 0, medians.size() - 1, ceil(medians.size() / 2.0));

    int i;
    for(i = s; i <= e; i++) {
      if (nums[i] == m) break;
    }
    swap(nums[e], nums[i]);
    i = s;
    for(int j = s; j < e; j++) {
      if (nums[j] <= m) {
        swap(nums[i], nums[j]);
        i++;
      }
    }
    swap(nums[e], nums[i]);
    if (i == s + k - 1) {
      return m;
    } else if (i > s + k - 1) {
      return findMedian(nums, s, i - 1, k);
    } else {
      return findMedian(nums, i + 1, e, k - (i - s + 1));
    }
  }

};
