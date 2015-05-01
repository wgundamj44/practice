class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        map<char, string> m;
        string s = "abcdefghijklmnopqrstuvwxyz";
        int offset = 0;
        for(int i = 2; i <= 9; i++) {
            char key = to_string(i)[0];
            int count = (key == '7' || key == '9') ? 4 : 3;
            m[key] = s.substr(offset, count);
            offset += count;
        }
        
        if (digits == "") {
            return ret;
        }
        
        combine(digits, 0, m, "", ret);
        
        return ret;
    }
    
    void combine(string digits, int index, map<char, string>& m, string tmp, vector<string>& res) {
        char key = digits[index];
        for(int i = 0; i < m[key].length(); i++) {
            if (index == digits.length() - 1) {
                res.push_back(tmp + m[key].substr(i, 1));
            } else{
                combine(digits, index + 1, m, tmp + m[key].substr(i, 1), res);
            }
        }
    }
};