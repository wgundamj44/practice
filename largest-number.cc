#include "TreeNode.h"
using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](int a, int b) { return to_string(a) + to_string(b) > to_string(b) + to_string(a); });
        
        string ret = "";
        for(int i : num) {
            ret += to_string(i);
        }
        int i = 0;
        while (i < ret.length() && ret[i] == '0') {
            i++;
        }
        if (i == ret.length()) {
            return "0";
        } else {
            return ret.substr(i, ret.length());
        }
    }
};
