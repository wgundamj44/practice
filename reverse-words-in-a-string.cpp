#include<string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, len = s.length();
        for(i = len - 1; i >= 0; i--) {
            if (s[i] == ' ') continue;
            
            int j = i;
            while(i >= 0 && s[i] != ' ') {
                i--;
            }
            
            string tmp = s.substr(i + 1, j - i);
            if (s.length() == len) {
                s += tmp;
            } else {
                s += (" " + tmp);
            }
        }
        if (s.length() > len) {
            s = s.substr(len);
        } else {
            s = "";
        }
    }
};
