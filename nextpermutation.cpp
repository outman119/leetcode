class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.empty() ||
            num.size() == 1)
        {
            return;
        }
        int len = num.size();
        int i = 0, j = 0;
        for (i = len - 2; i > 0; i--)
        {
            if (num[i] < num[i+1])
            {
                break;
            }
        }
        for (j = len - 1; j > i; j--)
        {
            if (num[j] > num[i])
            {
                break;
            }
        }
        if (i != j)
        {
            swap(num[i], num[j]);
            reverse(num.begin() + i + 1, num.end());
        }
        else
        {
            reverse(num.begin(), num.end());
        }
        return;
    }
};
