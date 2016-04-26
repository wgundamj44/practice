class Solution {
public:
  //check
  int maxProduct(vector<string>& words) {
    vector<int> m = vector<int>(words.size(), 0);
    int ret = 0;

    for(int i = 0; i < words.size(); i++) {
      string s= words[i];
      int mask = 0;
      for(char c: s) {
        mask = mask | (1 << (c - 'a'));
      }
      m[i] = mask;
    }
    for(int i = 0; i < words.size(); i++) {
      for(int j = i + 1; j < words.size(); j++) {
        if ((m[i] & m[j]) == 0) {
          if (words[i].length() *words[j].length() > ret) {
            ret = words[i].length() * words[j].length();
          }
        }
      }
    }
    return ret;
  }
};
