#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        vector<char> res(len1 + len2, '0');
        
        for(int i = len1 -1 ; i >=0; i--) {
            int c1 = num1[i] - '0';
            int carry = 0;
            for(int j = len2 - 1; j>=0; j--) {
                int c2 = num2[j] - '0';
                int value = (c1 * c2 + carry + (res[i + j + 1] - '0')) % 10;
                carry = (c1 * c2 + carry + (res[i + j + 1] - '0')) / 10;
                
                res[i + j + 1] = value + '0';
            }
            if (carry > 0) {
                int v = carry + (res[i] - '0');
                if (v >= 10) {
                    v -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                res[i] = v + '0';
            }
        }
        int i;
        for(i = 0; i < res.size(); i++) {
            if (res[i] != '0') {
                break;
            }
        }
        
        if (i == res.size()) return "0";
        
        string ret = "";
        for(; i < res.size() ;i++) {
            ret = ret + res[i];
        }
        
        return ret;
    }
    
};