class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n==0)
        {
            return vector<vector<int>>();
        }
        vector<int>rr;
        for(int i = 1; i <= n*n; i++)
        {
            rr.push_back(i);
        }
        vector<vector<int>>ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i].resize(n);
        }
        int start1 = 0, start2 = 0;
        int end1 = n-1, end2 = n-1;
        int mm = 0;
        for (int i = 0; mm != n*n; i++)
        {
            if (i % 4 == 0)
            {
                for (int j = start1; j <= end1; j++)
                {
                    ret[start2][j] = rr[mm];
                    mm++;
                }
                start2++;
            }
            else if (i % 4 == 1)
            {
                for (int j = start2; j <= end2; j++)
                {
                    ret[j][end1] = rr[mm];
                    mm++;
                }
                end1--;
            }
            else if (i % 4 == 2)
            {
                for (int j = end1; j >= start1; j--)
                {
                    ret[end2][j] = rr[mm];
                    mm++;
                }
                end2--;
            }
            else
            {
                for (int j = end2; j >= start2; j--)
                {
                    ret[j][start1] = rr[mm];
                    mm++;
                }
                start1++;
            }
        }
        return ret;
    }
};
