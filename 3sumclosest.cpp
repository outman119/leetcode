class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3)
        {
            return 0;
        }
        sort(num.begin(), num.end());
        int minal = abs(num[0] + num[1] + num[2] - target);
        int cc = num[0] + num[1] + num[2];
        for (unsigned int i = 0; i < num.size(); i++)
        {
            if (i != 0 && num[i] == num[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k)
            {
                if (j != i + 1 && num[j] == num[j - 1])
                {
                    j++;
                    continue;
                }
                if (k != num.size() - 1 && num[k] == num[k + 1])
                {
                    k--;
                    continue;
                }
                int sum = num[i] + num[j] + num[k];
                if (sum == target)
                {
                    return target;
                }
                else if (sum > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
                int div = abs(sum - target);
                if (div < minal)
                {
                    minal = div;
                    cc = sum;
                }
            }
        }
        return cc;
    }
};
