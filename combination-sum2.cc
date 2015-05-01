class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> res;
        vector<int> tmp;
        solve(candidates, 0, target, res, tmp);
        
        return vector<vector<int>>(res.begin(), res.end());
    }
    
    void solve(vector<int>& ca, int i, int target, set<vector<int>>& res, vector<int> tmp) {
       if (i >= ca.size()) return;
       int count = target / ca[i];
       if (count == 0) return;
       
       solve(ca, i + 1, target, res, tmp);
       
        tmp.push_back(ca[i]);
        target -= ca[i];
        if (target == 0) {
            res.insert(tmp);
            return;
        }
        solve(ca, i + 1, target, res, tmp);
    }
};