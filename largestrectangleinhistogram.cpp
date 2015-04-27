class Solution {
public:
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
