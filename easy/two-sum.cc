#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        set<int> presence;
        for(int i: numbers) {
            presence.insert(i);
        }
        for(int i = 0; i < numbers.size(); i++) {
            if (presence.find(target - numbers[i]) != presence.end()) {
                for(int j = i + 1; j < numbers.size(); j++) {
                    if (numbers[j] == target - numbers[i]) {
                        return {i + 1, j + 1};    
                    }
                }
            }
        }
    }
};
