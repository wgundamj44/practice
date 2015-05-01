class Solution {
public:
    string countAndSay(int n) {
        string s = "";
        for(int i = 1 ; i <=n ; i++) {
            if (i == 1) {
                s = "1";
                continue;
            }
            int j = 0, count = 1;
            char t = s[0];
            string tmp = "";
            while(j < s.length()) {
                if (j == 0) {
                    j++;
                    continue;
                }
                if (s[j] == t) {
                    count++;
                    j++;
                } else {
                    tmp += (to_string(count) + string(&t, sizeof(char)));
                    count = 1;
                    t = s[j];
                    j++;
                }
            }
            tmp += (to_string(count) + string(&t, sizeof(char)));
            s = tmp;
        }
        
        return s;
    }
};