class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string>ret;
        if (strs.empty())
        {
            return ret;
        }
        map<string, int>ma;
        vector<bool>pu(strs.size(), false);
        for (unsigned int i = 0; i < strs.size(); i++)
        {
            auto str = strs[i];
            sort(str.begin(), str.end());
            if (ma.count(str) == 0)
            {
                ma[str] = i;
            }
            else
            {
                if (pu[ma[str]] == false)
                {
                    ret.push_back(strs[ma[str]]);
                    pu[ma[str]] = true;
                }
                ret.push_back(strs[i]);
                pu[i] = true;
            }
        }
        return ret;
    }
};
