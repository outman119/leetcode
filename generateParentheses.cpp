class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string>ret;
        if (n <= 0)
        {
            return ret;
        }
        string s;
        s.push_back('(');
        int count = 1;
        int index = 1;
        getPa(n*2, index, count, s, ret);
        return ret;
    }
private:
    void getPa(int n, int index, int count, string &s, vector<string>&ret)
    {
        if (s.length() == n && count == 0)
        {
            ret.push_back(s);
            return;
        }
        if (count < 0)
        {
            return;
        }
        for (int i = index; i < n; i++)
        {
            //push (
            s.push_back('(');
            count++;
            getPa(n, i + 1, count, s, ret);
            s.pop_back();
            count--;
            //push )
            s.push_back(')');
            count--;
            getPa(n, i + 1, count, s, ret);
            s.pop_back();
            count++;
        }
        return;
    }
};
