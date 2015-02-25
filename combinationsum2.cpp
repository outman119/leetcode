class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>>ret;
        if (num.empty())
        {
            return ret;
        }
        int end = 0;
        int start = 0;
        sort(num.begin(), num.end());
        for (; end < num.size(); end++)
        {
            if (num[end]>target)
            {
                break;
            }
        }
        end--;
        vector<int>tmp;
        getComSum(num, target, start, end, tmp, ret);
        return ret;
    }
private:
    void getComSum(vector<int> &candidates, int target, int start, int end, vector<int>&tmp, vector<vector<int>>&ret)
    {
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
            if (i != start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            tmp.push_back(candidates[i]);
            getComSum(candidates, target - candidates[i], i+1, end, tmp, ret);
            tmp.pop_back();
        }
        return;
    }
};
