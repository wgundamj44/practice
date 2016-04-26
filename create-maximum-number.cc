class Solution {
public:
  //check
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> max_nums1(k + 1, vector<int>());
    vector<vector<int>> max_nums2(k + 1, vector<int>());
    generate_max_nums(nums1, max_nums1, k);
    generate_max_nums(nums2, max_nums2, k);
    vector<int> cur;
    for(int i = 0; i <= k; i++) {
      if (max_nums1[i].size() + max_nums2[k-i].size() < k) continue;
      auto tmp = merge(max_nums1[i], max_nums2[k-i]);
      if (cur.size() == 0) cur = tmp;
      else {
        if (smaller(cur, tmp)) {
          cur = tmp;
        }
      }
    }
    return cur;
  }

  bool smaller(vector<int>& n1, vector<int>& n2) {
    for(int i = 0; i< n1.size(); i++) {
      if (n1[i] < n2[i]) return true;
      else if (n1[i] > n2[i]) return false;
    }
    return false;
  }
  vector<int> merge(vector<int>& max_nums1, vector<int>& max_nums2) {
    int i = 0, j = 0;
    vector<int> ret;
    for(; i < max_nums1.size() && j < max_nums2.size(); ) {
      int ii = i, jj = j;
      for(; ii < max_nums1.size() && jj < max_nums2.size() && max_nums1[ii] == max_nums2[jj]; ii++, jj++);
      if (ii == max_nums1.size() && jj == max_nums2.size()) break;
      if (ii == max_nums1.size()) {
        for(; j < jj; j++) {
          ret.push_back(max_nums2[j]);
        }
      } else if (jj == max_nums2.size()) {
        for(; i < ii; i++) {
          ret.push_back(max_nums1[i]);
        }
      } else {
        if (max_nums1[ii] > max_nums2[jj]) {
          ret.push_back(max_nums1[i++]);
        } else {
          ret.push_back(max_nums2[j++]);
        }
      }
    }
    for(; i < max_nums1.size(); i++) ret.push_back(max_nums1[i]);
    for(; j < max_nums2.size(); j++) ret.push_back(max_nums2[j]);
    return ret;
  }


  void generate_max_nums(vector<int>& nums, vector<vector<int>>& max_nums, int k) {
    vector<int> tmp = nums;
    if (nums.size() <= k) max_nums[nums.size()] = tmp;
    for(int i = nums.size() - 1; i > 0; i--) {
      int j = 0;
      for(int z = j; z < tmp.size(); z++) {
        if (tmp[z] < tmp[z+1]) {
          tmp.erase(tmp.begin() + z);
          break;
        }
        if (z == tmp.size() - 1) {
          tmp.pop_back();
        }
      }
      if (i <= k) {
        max_nums[i] = tmp;
      }
    }
  }

};
