class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int len = num.size();
        int min = INT_MAX;
        int sum = 0;
        for(int i = 0;i < len - 2; i++) {
            int goal = target - num[i];
            int j = i + 1, k = len - 1;
            while(j < k) {
                int s = (num[j] + num[k] - goal);
                if (abs(s) < min) {
                   min = abs(s);
                   sum = num[i] + num[j] + num[k];
                }
                if (s == 0) {
                    return sum;
                } else if (s > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        
        return sum;
    }
};