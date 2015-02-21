class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 && n == 0)
        {
            return 0;
        }
        if (m==0||n==0)
        {
            return 1;
        }
        vector<vector<int>>ret(m);
        for (int i = 0; i < m; i++)
        {
            ret[i].resize(n);
        }
        ret[0][0] = 1;
        for (int i = 1; i < n; i++)
        {
            ret[0][i] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            ret[i][0] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
            }
        }
        return ret[m-1][n-1];
    }
};
