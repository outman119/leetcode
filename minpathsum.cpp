class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty())
        {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i].resize(m);
        }
        ret[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            ret[0][i] = grid[0][i] + ret[0][i - 1];
        }

        for (int i = 1; i < n; i++)
        {
            ret[i][0] = grid[i][0] + ret[i-1][0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                ret[i][j] = min(ret[i - 1][j], ret[i][j - 1]) + grid[i][j];
            }
        }
        return ret[n-1][m-1];
    }
};
