#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        bool flag[len][len];
        memset(flag, false, sizeof(flag));
        int start = len - 1, end = 0;
        for(int i = len - 1;i >= 0; i--) {
            for(int j = i; j < len; j++) {
                if (i == j) flag[i][j] = true;
                else if (i == j -1) {
                    flag[i][j] = (s[i] == s[j]);
                } else {
                    flag[i][j] = flag[i+1][j-1] ? s[i] == s[j] : false;
                }
                if (flag[i][j]) {
                    if (j - i > end -start) {
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};
