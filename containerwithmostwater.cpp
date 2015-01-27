class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() < 2)
        {
            return 0;
        }
        int len = height.size();
        int low = 0;
        int high = len - 1;
        int ret = 0;
        while (low < high)
        {
            ret = max(ret, min(height[low], height[high])*(high - low));
            if (height[low] > height[high])
            {
                while (high > low)
                {
                    high--;
                    if (height[high] > height[high+1])
                    {
                        break;
                    }
                }
            }
            else
            {
                while (high > low)
                {
                    low++;
                    if (height[low] > height[low-1])
                    {
                        break;
                    }
                }
            }
        }
        return ret;
    }
};
