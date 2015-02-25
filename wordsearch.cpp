class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || word.empty())
        {
            return false;
        }
        int r = board.size();
        int l = board[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < l; j++)
            {
                if (board[i][j] == word[0])
                {
                    vector<bool>visit(r*l, false);
                    
                    if (search(board, word, visit, i, j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    bool search(vector<vector<char> > &board, string word, vector<bool>visit, int i, int j)
    {
        int r = board.size();
        int l = board[0].size();
        if (i < 0 || j < 0 || i >=r || j>=l)
        {
            return false;
        }
        if (word.empty())
        {
            return true;
        }
        if (visit[i*l + j] == true)
        {
            return false;
        }
        if (board[i][j] == word[0])
        {
            if (word.length() == 1)
            {
                return true;
            }
            visit[i*l + j] = true;
            if (search(board, word.substr(1), visit, i-1, j) == true)
            {
                return true;
            }
            if (search(board, word.substr(1), visit, i + 1, j) == true)
            {
                return true;
            }
            if (search(board, word.substr(1), visit, i, j-1) == true)
            {
                return true;
            }
            if (search(board, word.substr(1), visit, i, j + 1) == true)
            {
                return true;
            }
        }
        return false;
    }
};
