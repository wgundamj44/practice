class Solution {
public:
    //first find a solution, then delete from head until it isn't a solution
    // then search forward until it becomes soluction again...
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        unordered_map<char, int> re;
        vector<int> li;
        
        for(int i = 0; i < t.length(); i++) {
            if (m.find(t[i]) != m.end()) {
                m[t[i]]++;
            } else {
                m[t[i]] = 1;   
            }
        }
        
        string ret = "";
        int c = 0;
        for(int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end()) {
                li.push_back(i);
                if (re.find(s[i]) != re.end()) {
                    re[s[i]]++;
                } else {
                    re[s[i]] = 1;
                }
                if (re[s[i]] <= m[s[i]]) {
                    c++;
                }
            } else {
                continue;
            }
            while(c == t.length()) {
                int j = *li.begin();
                string tmp = s.substr(j, li.back() - j + 1);
                li.erase(li.begin());
                if (ret == "" || tmp.length() < ret.length()) {
                    ret = tmp;
                }
                re[s[j]]--;
                if (re[s[j]] < m[s[j]]) {
                    c--;
                }
            }
        }
        
        return ret;
    }
};


class Solution2 {
  //check: another solution
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> m;
    unordered_map<char, int> targets;
    queue<int> q;
    for(char c: t) {
      m[c] = 0;
      if (targets.find(c) == targets.end()) targets[c] = 1;
      else targets[c]++;
    }
    int b = 0, e = -1;
    int found = 0;
    string res = "";
    for(int i = 0; i < s.length(); i++) {
      if (targets.find(s[i]) != targets.end()) {
        m[s[i]]++;
        if (m[s[i]] <= targets[s[i]]) found++;
        if (q.empty()) {
          q.push(i);
          b = i;
        } else {
          q.push(i);
          auto top = q.front();
          while(m[s[top]] > targets[s[top]]) {
            q.pop();
            m[s[top]]--;
            top = q.front();
            b = top;
          }
        }
        if (found == t.length()) {
          e = i;
          if (res == "" || e - b + 1 < res.length()) res = s.substr(b, e -b + 1);
        }
      }
    }
    return res;
  }
};
