class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>>ret;
        if (num.size() < 4)
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
            auto tmp = threeSum(num, i + 1, target - num[i]);
            for (unsigned int j = 0; j < tmp.size(); j++)
            {
                auto tmp1 = tmp[j];
                tmp1.insert(tmp1.begin(), num[i]);
                ret.push_back(tmp1);
            }
        }
        return ret;
    }
private:
    vector<vector<int> > threeSum(vector<int> &num, int index, int target) {
        vector<vector<int>>ret;
        if (num.size() -index < 3)
        {
            return ret;
        }
        for (unsigned int i = index; i < num.size(); i++)
        {
            if (i != index && num[i] == num[i - 1])
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
                if (sum > target)
                {
                    k--;
                }
                else if (sum < target)
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
