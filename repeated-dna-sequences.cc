#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    map<unsigned int, bool> seqs;
    vector<string> result;

    if (s.length() <= 10) return result;
    
    for(int i = 0; i <= s.length() - 10; i++) {
      string sub = s.substr(i, 10);
      unsigned int tmp = 0;
      for(int j = 0; j < sub.length(); j++) {
        switch(sub[j]) {
        case 'A': {
          tmp = tmp << 2 ;
          break;
        }
        case 'C': {
          tmp = (tmp << 2) | 0b01;
          break;
        }
        case 'G': {
          tmp = (tmp << 2) | 0b10;
          break;
        }
        case 'T': {
          tmp = (tmp << 2) | 0b11;
          break;
        }
        }
      }
      if (seqs.find(tmp) != seqs.end()) {
        if (seqs[tmp] == true) {
          seqs[tmp] = false;
        }
      } else {
        seqs[tmp] = true;
      }
    }
    for(auto it = seqs.begin(); it != seqs.end(); it++) {
      if (it->second == false) {
        unsigned int res = it->first;
        string sub = "";
        for(int i = 0; i < 10; i++) {
          unsigned int j = res & 0b11;
          switch(j) {
          case 0: {
            sub = "A" + sub;
            break;
          }
          case 1: {
            sub = "C" + sub;
            break;
          }
          case 2: {
            sub = "G" + sub;
            break;
          }
          case 3: {
            sub = "T" + sub;
            break;
          }
          }
          res = res >> 2;
        }
        result.push_back(sub);
      }
    }
    return result;
  }
};
