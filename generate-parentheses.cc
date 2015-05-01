class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> res;
        generate(s, 0, n, n * 2, res);
        
        return res;
    }
    
    void generate(string s, int i, int remain, int len, vector<string> & res) {
        if (i == len) {
            res.push_back(s);
            return;
        }
       
        if (remain > 0) {
            generate(s + "(", i + 1, remain - 1, len, res);
                // i - (len / 2 - remain) < (len / 2 - remain)
            if (i < len - 2 * remain) {
                generate(s + ")", i + 1, remain, len, res);
            }
        } else {
            generate(s + ")", i + 1, 0, len, res);
        }
    }
};