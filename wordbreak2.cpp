class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string>ret;
        if (s.empty() || dict.empty())
        {
            return ret;
        }
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 0; i < len; i++)
        {
            if (dp[i])
            {
                for (int j = 1; i + j - 1 < len; j++)
                {
                    if (dict.count(s.substr(i, j)) != 0)
                    {
                        dp[i + j] = true;
                    }
                }
            }
        }
        vector<string>tmp;
        if (dp[len])
        {
            getWord(s, dict, dp, 0, tmp, ret);
        }
        return ret;
    }
private:
    void getWord(string s, unordered_set<string> &dict, vector<bool> &dp, int index, vector<string>&tmp, vector<string>&ret)
    {
        if (index > s.length())
        {
            return;
        }
        if (index == s.length())
        {
            string ss;
            for (auto sss : tmp)
            {
                ss += sss;
                ss += ' ';
            }
            ret.push_back(ss.substr(0, ss.length()-1));
            return;
        }

        for (unsigned int i = 1; i <= s.length() -index; i++)
        {
            auto sss = s.substr(index, i);
            if (dp[i + index] && dict.count(sss)!=0)
            {
                tmp.push_back(sss);
                getWord(s, dict, dp, index + i, tmp, ret);
                tmp.pop_back();
            }
        }
        return;
    }
};
