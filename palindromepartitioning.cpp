class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty())
        {
            return vector<vector<string>>();
        }
        vector<vector<string>>ret;
        vector<string>path;
        dfs(s, path, ret);
        return ret;
    }
private:
    void dfs(string s, vector<string>&path, vector<vector<string>>&ret)
    {
        if (s.size() < 1)
        {
            ret.push_back(path);
            return;
        }
        for (unsigned int i = 0; i < s.length(); i++)
        {
            auto sub = s.substr(0, i + 1);
            if (isPalindrome(sub) == true)
            {
                path.push_back(sub);
                auto sub2 = s.substr(i + 1);
                dfs(sub2, path, ret);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string sub)
    {
        if (sub.length() <=1)
        {
            return true;
        }
        int begin = 0;
        int end = sub.length() - 1;
        while (begin < end)
        {
            if (sub[begin] != sub[end])
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};
