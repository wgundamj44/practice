class Solution {
public:
  //check
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    for(int i = citations.size() - 1; i >= 0; i--) {
      int h = citations.size() - i;
      if (citations[i] > h) {
        continue;
      } else if (citations[i] < h) {
        return h - 1;
      } else {
        return citations[i];
      }
    }
    return citations.size();
  }
};
