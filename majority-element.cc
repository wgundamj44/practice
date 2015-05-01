#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 1, m = num[0];
        for(int i = 1 ; i < num.size(); i++) {
            if (m == num[i]) {
                count++;
            } else {
                count -= 1;
                if (count == 0) {
                    m = num[i];
                    count = 1;
                }
            }
        }
        return m;
    }
};
