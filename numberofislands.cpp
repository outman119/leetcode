class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        if (m == 0)
        {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0)
        {
            return 0;
        }
        int ret = 0;
        for (int i = 0; i < m;i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != '1')
                {
                    continue;
                }
                ret++;
                mark(grid, i, j);
            }
        }
        return ret;
    }
private:
    void mark(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return;
        }
        if (grid[i][j] != '1')
        {
            return;
        }
        grid[i][j] = '0';
        mark(grid, i - 1, j);
        mark(grid, i, j - 1);
        mark(grid, i + 1, j);
        mark(grid, i, j + 1);
    }
};
