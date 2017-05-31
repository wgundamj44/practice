#include "common.h"

class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    bool checked = false;
    for(auto inter: intervals) {
      if (checked) {
        res.push_back(inter);
        continue;
      }
      if (inter.end < newInterval.start) {
        res.push_back(inter);
      } else if (inter.start > newInterval.end) {
        res.push_back(newInterval);
        res.push_back(inter);
        checked = true;
      } else if (inter.start <= newInterval.start && inter.end >= newInterval.end) {
        res.push_back(inter);
        checked = true;
      } else if (inter.start >= newInterval.start && inter.end <= newInterval.end) {
        continue;
      } else {
        if (inter.start <= newInterval.start) {
          newInterval.start = inter.start;
        } else {
          newInterval.end = inter.end;
        }
      }
    }
    if (!checked) res.push_back(newInterval);
    
    return res;
  }
};
