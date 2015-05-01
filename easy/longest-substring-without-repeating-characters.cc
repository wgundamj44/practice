class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        set<char> seen;
        int b = 0;
        int mLen = 0, len = 0;
        for(int i = 0; i < s.length(); i++) {
            if (seen.find(s[i])  != seen.end()) {
                while(b < i) {
                    seen.erase(s[b]);
                    if (s[b] == s[i]) {
                        b++;
                        break;
                    }
                    b++;
                }
            }
            seen.insert(s[i]);
            if (seen.size() > mLen) {
                mLen = seen.size();
            }
        }
        return mLen;
    }
};