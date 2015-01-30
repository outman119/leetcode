class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() <= 0)
        {
            return 0;
        }
        int len = triangle.size();
        vector<int>ret(triangle[len - 1]);
        for (int i = len-2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                ret[j] = triangle[i][j] + min(ret[j], ret[j+1]);
            }
        }
        return ret[0];
    }
private:
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
};
