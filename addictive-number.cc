class Solution {
public:
  //check
  bool isAdditiveNumber(string num) {
    for(int i = 0; i < num.size() / 2; i++) {
      for(int j = i + 1; j < num.size(); j++) {
        if (num[i+1] == '0' && j - i > 1) continue;
        int remain = num.size() -j -1;
        if (remain < i + 1 || remain < j - i) continue;
        string a1 = num.substr(0, i + 1);
        string a2 = num.substr(i + 1, j - i);
        int k = j + 1;
        while(k < num.size()) {
          string res = string_sum(a1, a2);
          if (res.size() > num.size() - k) break;
          int z;
          for(z = 0; z < res.size(); z++) {
            if (num[k + z] != res[z]) break;
          }
          if (z != res.size()) break;
          k = k + res.size();
          a1 = a2;
          a2 = res;
        }
        if (k == num.size()) return true;
      }
    }
    return false;
  }
  string string_sum(string a1, string a2) {
    int i = a1.size() - 1, j = a2.size() - 1;
    string s = "";
    int carry = 0;
    while(i >= 0  && j >= 0) {
      int r = (a1[i] - '0') + (a2[j] - '0') + carry;
      if (r >= 10) {
        s = to_string(r - 10) + s;
        carry = 1;
      } else {
        s = to_string(r) + s;
        carry = 0;
      }
      i--;
      j--;
    }
    int k = i < 0 ? j : i;
    string a = i < 0 ? a2 : a1;
    while(k >= 0) {
      int r = (a[k] - '0') + carry;
      if (r >= 10) {
        s = to_string(r - 10) + s;
        carry = 1;
      } else {
        s = to_string(r) + s;
        carry = 0;
      }
      k--;
    }
    if (carry) s = "1" + s;
    return s;
  }
};
