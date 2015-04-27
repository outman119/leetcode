/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int len = intervals.size();
        ret.clear();
        if (len == 0)
        {
            ret.push_back(newInterval);
            return ret;
        }
        bool flag = false;
        for (auto x : intervals)
        {
            if (x.end < newInterval.start)
            {
                ret.push_back(x);
            }
            else if (x.start > newInterval.end)
            {
                if (flag == false)
                {
                    ret.push_back(newInterval);
                    flag = true;
                }
                ret.push_back(x);

            }
            else if (x.start > newInterval.start && x.end < newInterval.end)
            {
                continue;
            }
            else
            {
                newInterval.start = min(x.start, newInterval.start);
                newInterval.end = max(x.end, newInterval.end);
            }

        }
        if (flag == false)
        {
            ret.push_back(newInterval);
        }
        return ret;
    }
private:
    vector<Interval>ret;
};
