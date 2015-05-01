class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        int i = 0;
        if (len2 == 0) return 0;
        if (len2 > len1) return -1;
        
        while(i < len1 - len2 + 1) {
            bool find = true;
            for(int j = 0; j < len2; j++) {
                if (haystack[i + j] != needle[j]) {
                    find = false;
                    break;
                }
            }
            if (find) {
                return i;
            }
            i++;
        }
        
        return -1;
    }
};