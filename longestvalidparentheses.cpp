class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len == 0)
        {
            return 0;
        }
        int count = 0;
        int maxc = 0;
        vector<int>mark(len, 0);
        stack<int>ss;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                ss.push(i);
            }
            else
            {
                if (ss.empty())
                {
                    continue;
                }
                else
                {
                    auto nn = ss.top();
                    mark[nn] = 1;
                    ss.pop();
                    mark[i] = 1;
                }
            }
        }
        for (auto x : mark)
        {
            if (x == 1)
            {
                count++;
                maxc = max(maxc, count);
            }
            else
            {
                count = 0;
            }
        }
        return maxc;
    }
};
