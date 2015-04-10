class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.length();
        int n = T.length();
        if (m < n || n ==0)
        {
            return 0;
        }
        vector<vector<int>>ss(n+1);
        for (int i = 0; i < n+1; i++)
        {
            ss[i].resize(m+1);
        }
        for(int i = 0; i < m+1; i++)
        {
            ss[0][i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (T[i-1] == S[j-1])
                {
                    ss[i][j] = ss[i][j-1] + ss[i-1][j - 1];
                }
                else
                {
                    ss[i][j] = ss[i][j-1];
                }
            }
        }
        return ss[n][m];
    }
};
