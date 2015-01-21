class Solution {
public:
    void reverseWords(string &s) {
    int len = s.length();
    if (len == 0)
    {
        return;
    }
    auto it = s.begin();
    while (it != s.end())
    {
        if (isspace(*it))
        {
            it = s.erase(it);
        }
        else
        {
            auto ij = it;
            while (ij != s.end())
            {
                if (!isspace(*ij))
                {
                    ij++;
                }
                else
                {
                    break;
                }
            }
            reverse(s, it, ij - 1);
            if (ij == s.end())
            {
                break;
            }
            else
            {
                it = ij + 1;
            }
        }
    }
    auto ij = s.end() - 1;
    if (isspace(*ij))
    {
        s.erase(ij);
    }
    if (s.length() <= 1)
    {
        return;
    }
    reverse(s, s.begin(), s.end() - 1);
    }
private:
    void reverse(string &s, string::iterator start, string::iterator end)
    {
        if (s.empty() ||
            start == s.end() ||
            end ==s.end() ||
            start == end)
        {
            return;
        }
 
        while (start < end)
        {
            char tmp = *start;
            *start = *end;
            *end = tmp;
            start++;
            end--;
        }
        return;
    }
};
