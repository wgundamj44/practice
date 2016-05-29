class Solution {
public:
    static bool cmp(Interval& left, Interval& right) {
        return left.start < right.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        auto pre = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= pre.end) {
                if (intervals[i].end >= pre.end) {
                    pre.end = intervals[i].end;
                }
            } else {
                res.push_back(pre);
                pre = intervals[i];
            }
        }
        res.push_back(pre);
        return res;
    }
};
