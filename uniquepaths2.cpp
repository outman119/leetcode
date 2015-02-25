class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty())
        {
            return 0;
        }
        if (obstacleGrid[0][0]==1)
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>ret(m);
        for (int i = 0; i < m; i++)
        {
            ret[i].resize(n);
        }
        ret[0][0] = 1;
        
        for (int i = 1; i < n; i++)
        {
            ret[0][i] = obstacleGrid[0][i]==0? ret[0][i - 1] : 0;
        }

        for (int i = 1; i < m; i++)
        {
            ret[i][0] = obstacleGrid[i][0]==0?ret[i-1][0]:0;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                ret[i][j] = obstacleGrid[i][j] == 0?
                    (ret[i - 1][j] + ret[i][j - 1]):0;
            }
        }
        return ret[m-1][n-1];
    }
};
