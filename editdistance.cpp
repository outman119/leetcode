class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0 || len2 == 0)
        {
            return len1 + len2;
        }
        vector<vector<int>>ret(len1+1, vector<int>(len2+1, 0));
        for (int i = 0; i <= len2; i++)
        {
            ret[0][i] = i;
        }
        for (int i = 0; i <= len1; i++)
        {
            ret[i][0] = i;
        }
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    ret[i][j] = ret[i - 1][j - 1];
                }
                else
                {
                    ret[i][j] = min(min(ret[i - 1][j], ret[i][j - 1]), ret[i - 1][j - 1]) + 1;;
                }
            }
        }
        return ret[len1][len2];
    }
};
