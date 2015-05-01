class Solution {
public:
    int longestValidParentheses(string s) {
        struct en {
            char c;
            int i;
        };
        int len = s.length();
        stack<en> st;
        for(int i = 0; i < len; i++) {
            if (st.size() != 0 && (st.top().c == '(' && s[i] == ')')) {
                st.pop();
            } else {
                en e;
                e.c = s[i];
                e.i = i;
                st.push(e);
            }
        }
        
        int i = len - 1;
        int j;
        int max = 0;
        if (st.size() == 0) {
            return len;
        }
        while(st.size() != 0) {
            j = st.top().i;
            int t = i - j;
            if (t > max) {
                max = t;
            }
            i = j - 1;
            st.pop();
        }
        // j is the last invalid one
        if (j > max) {
            max = j;
        }
        
        return max;
    }
};