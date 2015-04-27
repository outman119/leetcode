class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len3 != len1 + len2)
        {
            return false;
        }
        vector<vector<bool>>vv(len1+1, vector<bool>(len2+1, false));

        vv[0][0] = true;

        for (int i = 0; i < len1; i++)
        {
            vv[i + 1][0] = vv[i][0] && (s1[i] == s3[i]);
        }

        for (int i = 0; i < len2; i++)
        {
            vv[0][i+1] = vv[0][i] && (s2[i] == s3[i]);
        }
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                vv[i + 1][j + 1] = (vv[i][j+1] && s1[i] == s3[i +j +1]) +
                    (vv[i+1][j] && s2[j] == s3[i+j+1]);
            }
        }
        return vv[len1][len2];
    }
};
