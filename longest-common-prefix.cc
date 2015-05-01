#include "TreeNode.h"
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int index = 0;
        
        if (strs.size() == 0) {
            return "";
        }
        
        bool find = false;
        while(true) {
            char flag;
            for(int i = 0; i < strs.size(); i++) {
              // note: if we write strs[i].length() - 1 < index, left side will be VERY LARGE, because length() is ulong
                if (strs[i].length() < index + 1) {
                    find = true;
                    break;
                }
                if (i == 0) {
                    flag = strs[i][index];
                } else {
                    if (flag != strs[i][index]) {
                        find = true;
                        break;
                    }
                }
            }
            if (find) break;
            index++;
        }
        if (index == 0) return "";
        return strs[0].substr(0, index);
    }
};

int main() {
  Solution *s = new Solution();
  vector<string> input = {""};
  cout << s->longestCommonPrefix(input) << endl;
}
