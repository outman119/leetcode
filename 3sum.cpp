
iclass Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>>ret;
        if (num.size() < 3)
        {
            return ret;
        }
        sort(num.begin(), num.end());
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
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    vector<int>tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    ret.push_back(tmp);
                    j++;
                }
            }
        }
        return ret;
    }
};
