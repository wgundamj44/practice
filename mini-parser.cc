#include<string>
using namespace std;

class Solution {
public:
  NestedInteger deserialize(string s) {
    int b = 0;
    if (s[b] == '-' || (s[b] >= '0' && s[b] <= '9')) {
      return NestedInteger(parseInt(s, b, s.size() - 1));
    } else {
      NestedInteger res;
      b++;
      parse(res, s, b, s.size() - 1);
      return res;
    }

  }
  void parse(NestedInteger& parent, string& s, int& b, int e) {
    while(b <= e) {
      if ((s[b] >= '0' && s[b] <= '9') || s[b] == '-') {
        parent.add(NestedInteger(parseInt(s, b, e)));
      } else if (s[b] == ',') {
        b++;
      } else if (s[b] == '[') {
        NestedInteger child;
        b++;
        parse(child, s, b, e);
        parent.add(child);
      } else {
        b++;
        break;
      }
    }
  }
  
  int parseInt(string& s, int& b, int e) {
    int num = 0;
    int minus = false;
    if (s[b] == '-') {
      minus = true;
      b++;
    }
    while(b <= e && s[b] >= '0' && s[b] <= '9') {
      num = num * 10 + (s[b] - '0');
      b++;
    }
    return minus ? -1 * num : num;
  }
};
