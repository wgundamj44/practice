#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        vector<vector<int>> all;
        int i = 0;
        while(i < s.length()) {
            vector<int> tmp(nRows, -1);
            for(int j = 0; j < nRows; j++) {
                tmp[j] = s[i++];
                if (i == s.length()) break;
            }
            all.push_back(tmp);
            if (i == s.length()) break;
            for(int j = 0; j< nRows - 2; j++) {
                vector<int> tmp(nRows, -1);
                tmp[nRows - j - 2] = s[i++];
                all.push_back(tmp);
                if (i == s.length()) break;
            }
        }
        string ret = "";
        for(int i = 0; i < nRows; i++) {
            for(int j = 0; j < all.size(); j++) {
                if (all[j][i] != -1) {
                    ret += string(1, (char)all[j][i]);
                }
            }
        }
        
        return ret;
    }
};

int main() {
  Solution *s = new Solution();
  cout << s->convert("PAYPALISHIRING", 2) << endl;
}
