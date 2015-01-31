class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if (m < 1)
        {
            return;
        }
        int n = board[0].size();
        if (n < 1)
        {
            return;
        }
        typedef pair<int, int> point;
        queue<point>que;
        vector<vector<bool>>visit(m);
        for (int i = 0; i < m; i++)
        {
            visit[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                visit[i][j] = false;
            }
        }
       
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' &&
                visit[i][0] == false)
            {
                que.push(point(i, 0));
                visit[i][0] = true;
            }
            if (board[i][n - 1] == 'O' &&
                visit[i][n-1] == false)
            {
                que.push(point(i, n - 1));
                visit[i][n - 1] = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O' &&
                visit[0][i] == false)
            {
                que.push(point(0, i));
                visit[0][i] = true;
            }
            if (board[m-1][i] == 'O' && 
                visit[m-1][i] == false)
            {
                que.push(point(m - 1, i));
                visit[m - 1][i] = true;
            }
        }

        while (1)
        {
            if (que.empty())
            {
                break;
            }
            auto node = que.front();
            que.pop();
            int x = node.first;
            int y = node.second;
            if ((x == 0 && y == 0) ||
                (x == m-1 && y == n-1) ||
                (x == 0 && y == n-1) ||
                (x == m-1 && y== 0))
            {
                continue;
            }
            else if (x == 0)
            {
                if (board[1][y] == 'O' &&
                    visit[1][y] == false)
                {
                    que.push(point(1,y));
                    visit[1][y] = true;
                }
            }
            else if (x == m-1)
            {
                if (board[m-2][y] == 'O' &&
                    visit[m-2][y] == false)
                {
                    que.push(point(m-2, y));
                    visit[m - 2][y] = true;
                }
            }
            else if (y == 0)
            {
                if (board[x][1] == 'O' &&
                    visit[x][1] == false)
                {
                    que.push(point(x, 1));
                    visit[x][1] = true;
                }
            }
            else if (y == n - 1)
            {
                if (board[x][y - 1] == 'O' &&
                    visit[x][y - 1] == false)
                {
                    que.push(point(x, y - 1));
                    visit[x][y - 1] = true;
                }
            }
            else
            {

                if (board[x - 1][y] == 'O'&&
                    visit[x - 1][y] == false)
                {
                    que.push(point(x - 1, y));
                    visit[x - 1][y] = true;
                }
                if (board[x + 1][y] == 'O'&&
                    visit[x + 1][y] == false)
                {
                    que.push(point(x + 1, y));
                    visit[x + 1][y] = true;
                }
                if (board[x][y - 1] == 'O' &&
                    visit[x][y - 1] == false)
                {
                    que.push(point(x, y - 1));
                    visit[x][y - 1] = true;
                }
                if (board[x][y + 1] == 'O' &&
                    visit[x][y + 1] == false)
                {
                    que.push(point(x, y + 1));
                    visit[x][y + 1] = true;
                }
            }
        }
        for (int i = 1; i < m-1; i++)
        {
            for (int j = 1; j < n-1; j++)
            {
                if (board[i][j] == 'O' &&
                    visit[i][j] == false)
                {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
