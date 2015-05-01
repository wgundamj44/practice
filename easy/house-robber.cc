class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) return 0;
        
        vector<int> result;
        for(int i = 0;i < num.size(); i++) {
            if (i == 0) {
                result.push_back(num[i]);
            } else {
                int tmp = max(num[i] + (i - 2 >= 0 ? result[i - 2] : 0), result[i - 1]);
                result.push_back(tmp);
            }
        }
        return result[num.size() - 1];
    }
};