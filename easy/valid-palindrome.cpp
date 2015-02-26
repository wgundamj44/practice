#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int i = 0, j = len - 1;
        while(i < j && i < len && j >= 0) {
            if (!isAlpha(s.at(i))) {
                i++;
                continue;
            }
            if (!isAlpha(s.at(j))) {
                j--;
                continue;
            }
            if (tolower(s.at(i)) != tolower(s.at(j))) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isAlpha(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' and c <= '9')) {
            return true;
        }
        return false;
    }
};
