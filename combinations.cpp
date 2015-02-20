class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        tmp.clear();
        ret.clear();
        if (n < 1 || k < 1 || n < k)
        {
            return ret;
        }
        tmp.resize(k, 0);
        dfs(0, k, n, 1);
        return ret;
        
    }
private:
    void dfs(int depth, int maxdepth, int max, int start)
    {
        if (depth == maxdepth)
        {
            ret.push_back(tmp);
            return;
        }
        if (start > max)
        {
            return;
        }
        for (int i = start; i <= max; i++)
        {
            tmp[depth] = i;
            dfs(depth + 1, maxdepth, max, i + 1);
        }
        return;
    }
    vector<vector<int>>ret;
    vector<int>tmp;
};
