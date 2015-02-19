class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>>ret;
        ret.push_back(vector<int>());
        int len = S.size();
        if (len == 0)
        {
            return ret;
        }
        uint64_t all = (uint64_t)pow(2, len);
        vector<int>tmp;
        for (uint64_t i = 1; i < all; i++)
        {
            tmp.clear();
            auto index = 0;
            auto j = i;
            while (j != 0)
            {
                if (j&0x1)
                {
                    tmp.push_back(S[index]);
                }
                j = j >> 1;
                index++;
            }
            sort(tmp.begin(), tmp.end());
            ret.push_back(tmp);
            
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
