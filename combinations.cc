class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> res;
        pick(1, n, k, tmp, res);
        
        return res;
    }
    
    void pick(int i, int n, int k, vector<int> tmp, vector<vector<int>>& res) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        for(int j = i; j <= n; j++) {
            tmp.push_back(j);
            pick(j + 1, n, k, tmp, res);
            tmp.pop_back();
        }
    }
};
