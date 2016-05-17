#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

// class Solution {
// public:
//   vector<string> findRepeatedDnaSequences(string s) {
//     map<unsigned int, bool> seqs;
//     vector<string> result;

//     if (s.length() <= 10) return result;
    
//     for(int i = 0; i <= s.length() - 10; i++) {
//       string sub = s.substr(i, 10);
//       unsigned int tmp = 0;
//       for(int j = 0; j < sub.length(); j++) {
//         switch(sub[j]) {
//         case 'A': {
//           tmp = tmp << 2 ;
//           break;
//         }
//         case 'C': {
//           tmp = (tmp << 2) | 0b01;
//           break;
//         }
//         case 'G': {
//           tmp = (tmp << 2) | 0b10;
//           break;
//         }
//         case 'T': {
//           tmp = (tmp << 2) | 0b11;
//           break;
//         }
//         }
//       }
//       if (seqs.find(tmp) != seqs.end()) {
//         if (seqs[tmp] == true) {
//           seqs[tmp] = false;
//         }
//       } else {
//         seqs[tmp] = true;
//       }
//     }
//     for(auto it = seqs.begin(); it != seqs.end(); it++) {
//       if (it->second == false) {
//         unsigned int res = it->first;
//         string sub = "";
//         for(int i = 0; i < 10; i++) {
//           unsigned int j = res & 0b11;
//           switch(j) {
//           case 0: {
//             sub = "A" + sub;
//             break;
//           }
//           case 1: {
//             sub = "C" + sub;
//             break;
//           }
//           case 2: {
//             sub = "G" + sub;
//             break;
//           }
//           case 3: {
//             sub = "T" + sub;
//             break;
//           }
//           }
//           res = res >> 2;
//         }
//         result.push_back(sub);
//       }
//     }
//     return result;
//   }
// };

class Solution {
public:
  //check
  vector<string> findRepeatedDnaSequences(string s) {
    map<int, int> m;
    map<int, string> m1;
    int val = 0;
    for(int i = 0; i < s.length(); i++) {
      if (i <= 9) {
        val = (val << 2) | ((s[i] - 64) % 5);
        if (i == 9) {
          m[val] = 1;
          m1[val] = s.substr(0, 10);
        }
      } else {
        val = ((val << 2) | ((s[i] - 64) % 5)) & 0xfffff;
        m1[val] = s.substr(i - 9, 10);
        if (val == 348485) cout << s.substr(i - 9, 10) << endl;
        if (m.find(val) == m.end()) {
          m[val] = 1;
        } else {
          m[val]++;
        }
      }
    }
    vector<string> res;
    for(auto it = m.begin(); it != m.end(); it++) {
      if (it->second != 1) {
        cout << it->first << " " << m1[it->first] << endl;
        res.push_back(m1[it->first]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  //["TGGGGTATTG","GTGTCATGGG","ATGGGGTATT","GTCATGGGGT","GATGGTGTTT","GTTCTCACTA","GGGGTATTGG"]
  for(auto v: s.findRepeatedDnaSequences("CGACGCAATTTAGAACGGGCCGCACTGCAACCATTGCTCAGACAACGCATGAGTTAAATTTCACAAGTGATAGTGGCTTGCGAGACGTGGGTTGGTGGTAGCGTACGCCCGCTATTCGCCCCTAACGTGACGGGATTATAAGGTCGCTTCCCGGAATGCGCAGACGAGTCTCCGGTTTAGCCTAGACGTCTCACGCGCGCAAGGCGTCAGTTCTCACTATCTCGCACAGGTGTATTCTATTAGTTATGGGTTCTCACTACAGTCGGTTACTTCCTCATCCATTTCTGCATACGGGTCAACTAACAGTGTCATGGGGTATTGGGAAGGATGCGTTTTTAAACCCTCTCAGTAGCGCGAGGATGCCCACAAATACGACGGCGGCCACGGATCTAATGCGAAGCTAGCGACGCTTTCCAGCAACGAGCGCCCCACTTATGACTGCGTGGGGCGCTCCGCTTTCCTAGAGAACATAGATGGTGTTTTCGAATCGTAACCACTTA")) {
    cout << v << endl;
  }
}
