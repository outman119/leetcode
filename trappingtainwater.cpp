class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int len = height.size();
        if (len == 0)
        {
            return sum;
        }
        int left = 0; 
        int right = len - 1;
        int high = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                high = max(high, height[left]);
                sum += high - height[left];
                left++;
            }
            else
            {
                high = max(high, height[right]);
                sum += high - height[right];
                right--;
            }
        }
        return sum;
    }
};
