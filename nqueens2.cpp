class Solution {
public:
    int totalNQueens(int n) {
        count = 0;
        vector<int>state(n, -1);
        getNQueens(state, 0);
        return count;
    }
private:
    int count;
    void getNQueens(vector<int>&state, int row)
    {
        int n = state.size();
        if (row == n)
        {
            count++;
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
