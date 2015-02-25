class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int>ret;
        if (matrix.empty())
        {
            return ret;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        ret.resize(m*n);
        int start1 = 0, start2 = 0;
        int end1 = n-1, end2 = m-1;
        int mm = 0;
        for (int i = 0; mm != m*n; i++)
        {
            if (i % 4 == 0)
            {
                for (int j = start1; j <= end1; j++)
                {
                    ret[mm] = matrix[start2][j];
                    mm++;
                }
                start2++;
            }
            else if (i % 4 == 1)
            {
                for (int j = start2; j <= end2; j++)
                {
                    ret[mm] = matrix[j][end1];
                    mm++;
                }
                end1--;
            }
            else if (i % 4 == 2)
            {
                for (int j = end1; j >= start1; j--)
                {
                    ret[mm] = matrix[end2][j];
                    mm++;
                }
                end2--;
            }
            else
            {
                for (int j = end2; j >= start2; j--)
                {
                    ret[mm] = matrix[j][start1];
                    mm++;
                }
                start1++;
            }
        }
        return ret;
    }
};
