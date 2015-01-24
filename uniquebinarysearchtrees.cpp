class Solution {
public:
    int numTrees(int n) {
        if (n <= 0)
        {
            return 1;
        }
        vector<int> ret;
        ret.push_back(1);
        ret.push_back(1);
        for (int i = 2; i <= n; i++)
        {
            int count = 0;
            for (int j = 1; j <= i; j++)
            {
                count += ret[j-1] * ret[i - j];
            }
            ret.push_back(count);
        }
        return ret[n];
    }
};
