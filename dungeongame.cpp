class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        if (m == 0)
        {
            return 0;
        }
        int n = dungeon[0].size();
        if (n == 0)
        {
            return 0;
        }
        vector<vector<int>>count(m, vector<int>(n,0));
        count[m - 1][n - 1] = max(1, 1-dungeon[m - 1][n - 1]);
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    continue;
                }
                else if (i == m - 1)
                {
                    count[i][j] = max(1, count[i][j+1] -dungeon[i][j]);
                }
                else if (j == n - 1)
                {
                    count[i][j] = max(1, count[i+1][j] - dungeon[i][j]);
                }
                else
                {
                    count[i][j] = max(1, min(count[i + 1][j], count[i][j+1]) - dungeon[i][j]);
                }
            }
        }
        return  count[0][0];
    }
};
