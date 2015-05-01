class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while(n > 0) {
            int re = n % 26;
            string sc = string(1, re == 0 ? 'Z' : (char)(re - 1 + 'A'));
            s = sc + s;
            n = n / 26;
            if (re == 0)  {
                n -= 1;
            }
        }
        
        return s;
    }
};
