class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        ret.clear();
        vector<int>state(n, -1);
        getNQueens(state, 0);
        return ret;
    }
private:
    vector<vector<string>>ret;
    void getNQueens(vector<int>&state, int row)
    {
        int n = state.size();
        if (row == n)
        {
            vector<string>tmp(n, string(n, '.'));
            for (int i = 0; i < n; i++)
            {
                tmp[i][state[i]] = 'Q';
            }
            ret.push_back(tmp);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(state, row, col))
            {
                state[row] = col;
                getNQueens(state, row + 1);
                state[row] = -1;
            }
        }
    }
    bool isValid(vector<int>&state, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            if (state[i] == col || abs(row-i) == abs(col -state[i]))
            {
                return false;
            }
        }
        return true;
    }
};
