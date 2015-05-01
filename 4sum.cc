class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        //use set to eliminate duplicates.
        set<vector<int>> qua;
        int len = num.size();
        if (len < 4) {
            return res;
        }
        sort(num.begin(), num.end());
        for(int i = 0; i < len; i++) {
            for(int j = i + 3; j < len; j++) {
                int k = i + 1, z = j - 1;
                int s = target - (num[i] + num[j]);
                while(k < z) {
                    int s2 = num[k] + num[z];
                    if (s2 == s) {
                        qua.insert({num[i], num[k], num[z], num[j]});
                        int tmp1 = num[k], tmp2 = num[z];
                        while(k < z && tmp1 == num[k]) k++;
                        while(k < z && tmp2 == num[z]) z--;
                    } else if (s2 > s) {
                        z--;
                    } else {
                        k++;
                    }
                }
            }
        }
    
        return vector<vector<int>>(qua.begin(), qua.end());
    }
};