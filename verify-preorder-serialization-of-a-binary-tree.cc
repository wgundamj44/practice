class Solution {
public:
  bool isValidSerialization(string preorder) {
    queue<string> q1, q2;
    if (preorder == "") return true;
    int i = 0;
    q1.push(nextToken(preorder, i));
    while(!q1.empty()) {
      while(!q1.empty()) {
        string t = q1.front();
        q1.pop();
        if (t == "#") continue;
        string n = nextToken(preorder, i);
        if (n == "") return false;
        q2.push(n);
        n = nextToken(preorder, i);
        if (n == "") return false;
        q2.push(n);
      }
      q1 = q2;
      q2 = queue<string>();
    }
    if (q1.empty() && i == preorder.size()) return true;
    else return false;
  }

  string nextToken(string& s, int& i) {
    int j = i;
    while(i < s.size()) {
      if (s[i] == ',') break;
      i++;
    }
    if (i == s.size()) {
      if (j == i) return "";
      else return s.substr(j, i - j + 1);
    } else {
      i++;
      return s.substr(j, i - j-1);
    }
  }
};
