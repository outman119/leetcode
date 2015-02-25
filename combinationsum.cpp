class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>>ret;
        if (candidates.empty())
        {
            return ret;
        }
        int end = 0;
        int start = 0;
        sort(candidates.begin(), candidates.end());
        for (; end < candidates.size(); end++)
        {
            if (candidates[end]>target)
            {
                break;
            }
        }
        end--;
        vector<int>tmp;
        getComSum(candidates, target, start, end, tmp, ret);
        return ret;
    }
private:
    void getComSum(vector<int> &candidates, int target, int start, int end, vector<int>&tmp, vector<vector<int>>&ret)
    {
        if (candidates.empty() || start>end || start < 0 || end >= candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            if (tmp.empty() != true)
            {
                ret.push_back(tmp);
            }
            return;
        }
        else if (target < 0)
        {
            return;
        }
        for (int i = start; i <= end; i++)
        {
            tmp.push_back(candidates[i]);
            getComSum(candidates, target - candidates[i], i, end, tmp, ret);
            tmp.pop_back();
        }
        return;
    }
};
