/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval &a, Interval &b)
{
    if (a.start == b.start)
    {
        return a.end < b.end;
    }
    return a.start < b.start;
}
class Solution {
public:
    
    vector<Interval> merge(vector<Interval> &intervals) {
        int len = intervals.size();
        ret.clear();
        if (len == 0)
        {
            return ret;
        }
        sort(intervals.begin(), intervals.end(), comp);
        Interval nn(intervals[0].start, intervals[0].end);
        for (int i = 1; i < len; i++)
        {
            if (intervals[i].start > nn.end)
            {
                ret.push_back(nn);
                nn.start = intervals[i].start;
                nn.end = intervals[i].end;
            }
            else
            {
                nn.end = max(nn.end, intervals[i].end);
            }
        }
        ret.push_back(nn);
        return ret;
    }
private:
    vector<Interval>ret;

};
