class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0)
        {
            return 0;
        }
        vector<int>ret(len,0);
        auto tmp = s.substr(0, 1);
        if (isvalid(tmp))
        {
            ret[0] = 1;
        }
        if (len < 2)
        {
            return ret[0];
        }
        tmp = s.substr(0, 2);
        if (isvalid(tmp))
        {
            ret[1] = 1;
        }
        tmp = s.substr(1, 1);
        if (isvalid(tmp))
        {
            ret[1] += ret[0];
        }
        
        for (int i = 2; i < len; i++)
        {
            if (isvalid(s.substr(i, 1)))
            {
                ret[i] += ret[i - 1];
            }
            if (isvalid(s.substr(i - 1, 2)))
            {
                ret[i] += ret[i - 2];
            }
        }
        return ret[len - 1];

    }
private:
    bool isvalid(string s)
    {
        if (s.length() > 2 ||
            s.length() == 0)
        {
            return false;
        }
        if (s.at(0) == '0')
        {
            return false;
        }
        int t = stoi(s);
        if (t > 26 || t <= 0)
        {
            return false;
        }
        return true;
    }
};
