class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty())
        {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        if (m != n || m == 1)
        {
            return;
        }
        for (int i = 0; i < m/2; i++)
        {
            for (int j = 0; j < m; j++)
            {
                swap(matrix[i][j], matrix[m-1-i][j]);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = i+1; j < m; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
};
