class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
        {
            return num1 + num2;
        }
        int flag1 = 0, flag2 = 0;
        if (num1[0] == '-')
        {
            flag1 = 1;
            num1 = num1.substr(1);
        }
        if (num2[0] == '-')
        {
            flag2 = 1;
            num2 = num2.substr(1);
        }
        int len1 = num1.length();
        int len2 = num2.length();
        int len = len1 + len2 + 1;
        vector<int> ret(len, 0);
        for (int i = len1-1; i >=0; i--)
        {
            vector<int>tmp(len, 0);
            int nn1 = num1[i] - '0';
            for (int j = len2-1; j >=0; j--)
            {
                int nn2 = num2[j] - '0';
                auto r = nn1*nn2;
                tmp[len1 -1 -i + len2-1-j] += nn1*nn2 % 10;
                tmp[len1 - 1 - i + len2 - 1 - j+1] += nn1*nn2 / 10;
            }
            addvector(tmp, ret);
        }
        string s;
        int index = ret.size()-1;
        for (; index >= 0; index--)
        {
            if (ret[index] != 0)
            {
                break;
            }
        }
        if (index == -1)
        {
            s += '0';
            return s;
        }
        for (int i = index; i >= 0; i--)
        {
            s +=(ret[i] + '0');
        }
        if (flag1 + flag2 == 1)
        {
            s.insert(0, 1, '-');
        }
        return s;
    }
private:
    void addvector(vector<int>tmp, vector<int>&ret)
    {
        int flag = 0;
        for (int i = 0; i < ret.size(); i++)
        {
            ret[i] += tmp[i] + flag;
            flag = 0;
            if (ret[i] >= 10)
            {
                flag = ret[i]/10;
                ret[i] = ret[i]%10;
            }
        }
        return;
    }
};
