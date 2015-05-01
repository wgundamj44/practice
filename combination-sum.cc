class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        solve(candidates, 0, target, res, tmp);
        
        return res;
    }
    
    void solve(vector<int>& ca, int i, int target, vector<vector<int>>& res, vector<int> tmp) {
       if (i >= ca.size()) return;
       int count = target / ca[i];
       if (count == 0) return;
       
       solve(ca, i + 1, target, res, tmp);
       for(int j = 1; j <= count; j++) {
           tmp.push_back(ca[i]);
           target -= ca[i];
           if (target == 0) {
               res.push_back(tmp);
               return;
           }
           solve(ca, i + 1, target, res, tmp);
       }
    }
};