class Solution {
public:
  //check
  int hIndex(vector<int>& citations) {
    int b = 0, e = citations.size() - 1;
    int h = citations.size();
    if (h == 0) return 0;
    while(b < e) {
      int mid = b + (e - b) / 2;
      if (citations[mid] > h - mid) {
        e = mid - 1;
      } else if (citations[mid] < h - mid) {
        b = mid + 1;
      } else {
        return citations[mid];
      }
    }
    if (citations[b] >= h - b) {
      return h - b;
    } else {
      return h -b - 1;
    }
  }
};
