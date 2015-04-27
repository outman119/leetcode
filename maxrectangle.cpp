class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0)
        {
            return 0;
        }
        vector<vector<int>>ss(m, vector<int>(n,0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    ss[i][j] = (matrix[i][j] == '1') ? 1 : 0;
                }
                else
                {
                    ss[i][j] = (matrix[i][j] == '1') ? (ss[i-1][j]+1) : 0;
                }
            }
        }
        
        int maxaa = 0;
        for (int i = 0; i < m; i++)
        {
            auto tmp = largestRectangleArea(ss[i]);
            maxaa = max(maxaa, tmp);
        }
        return maxaa;
    }
private:
    int largestRectangleArea(vector<int> &height) {
        int len = height.size();
        if (len == 0)
        {
            return 0;
        }
        int maxaera = 0;
        stack<int>ss;
        int i = 0;
        while (i < len)
        {
            if (ss.empty() || height[ss.top()] < height[i])
            {
                ss.push(i);
                i++;
            }
            else
            {
                int tmp = ss.top();
                ss.pop();
                auto area = height[tmp]*(ss.empty()?i:(i-ss.top()-1));
                maxaera = max(area, maxaera);
            }
        }

        while (!ss.empty())
        {
            int tmp = ss.top();
            ss.pop();
            auto area = height[tmp] * (ss.empty() ? i : (i - ss.top() - 1));
            maxaera = max(area, maxaera);
        }
        return maxaera;
    }
};
