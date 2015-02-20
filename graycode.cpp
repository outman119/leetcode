class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ret(1, 0);
        for (int i = 1; i < pow(2, n); i++)
        {
            auto t = i^(i>>1);
            ret.push_back(t);
        }
        return ret;
    }
};
