class Solution {
public:
    int findMin(vector<int> &num) {
        int len = num.size();
        if (len == 0)
        {
            return 0;
        }
        else if (len == 1)
        {
            return num[0];
        }
        int min = num[0];
        for (int i = 1; i < len; i++)
        {
            min = std::min(num[i], min);
        }
        return min;
    }
};
