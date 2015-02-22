class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int>> ret;
        ret.push_back(num);
        if (num.size() == 1 || num.size() == 0)
        {
            return ret;
        }
        auto tmp(num);
        while (nextPermutation(num) == true && tmp!=num)
        {
            ret.push_back(num);
        }
        return ret;

    }
private:
    bool nextPermutation(vector<int> &num) {
        if (num.empty() ||
            num.size() == 1)
        {
            return false;
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
        return true;
    }
};
