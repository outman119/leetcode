class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if (len == 0)
        {
            return 0;
        }
        vector<int>count(len+1, 0);
        for (int i = 0; i < len + 1; i++)
        {
            count[i] = len - i;
        }
        vector<vector<int>>ispa(len);
        for (int i = 0; i < len; i++)
        {
            ispa[i].resize(len);
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                ispa[i][j] = 0;
            }
        }

        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i; j < len; j++)
            {
                if ((s[i] == s[j]) &&
                    ((j - i < 2) || (ispa[i+1][j-1] == 1)))
                {
                    ispa[i][j] = 1;
                    count[i] = min(count[i], 1 + count[j + 1]);
                }
            }
        }
        return count[0] - 1;
    }
};
