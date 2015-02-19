iclass Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12)
        {
            return vector<string>();
        }
        vector<string>ret;
        string tmp;
        int times = 0;
        int index = 0;
        divide(s, tmp, times, index, ret);
        return ret;
    }
private:
    void divide(string s, string tmp, int times, int index, vector<string>&ret)
    {
        if (times >3)
        {
            return;
        }
        else if (times == 3)
        {
            int len = s.length();
            if (index >= len)
            {
                return;
            }
            auto tt = s.substr(index);
            if (!isvalid(tt))
            {
                return;
            }
            tmp += '.' + tt;
            ret.push_back(tmp);
            return;
        }
        int ii = 0;
        auto ss = tmp;
        for (ii = 1; ii <= 3; ii++)
        {
            tmp = ss;
            int len = s.length();
            if (index >= len)
            {
                continue;
            }
            auto t = s.substr(index, ii);
            if (!isvalid(t))
            {
                continue;
            }
            if (tmp.empty())
            {
                tmp += t;
            }
            else
            {
                tmp += '.' + t;
            }
            divide(s, tmp, times + 1, index + ii, ret);
        }
        return;

    }
    bool isvalid(string tt)
    {
        if (tt.empty())
        {
            return false;
        }
        if (tt.length() != 1 && tt.at(0) == '0')
        {
            return false;
        }
        int t = stoi(tt);
        if (t < 0 || t> 255)
        {
            return false;
        }
        return true;
    }
    
};
