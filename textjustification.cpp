class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ret;
        int num = words.size();
        int len = words[0].length();
        int start = 0;
        for (int i = 1; i < num; i++)
        {
            if (len + words[i].length() + 1 > maxWidth)
            {
                auto res = addSpace(words, start, i-1, len, maxWidth);
                ret.push_back(res);
                start = i;
                len = words[i].length();
            }
            else
            {
                len += words[i].length() + 1;
            }
        }
        auto res = addLast(words, start, num-1, maxWidth);
        ret.push_back(res);
        return ret;
    }
private:
    string addSpace(vector<string>& words, int start, int end, int len, int maxWidth)
    {
        string ret;
        if (end < start)
        {
            return ret;
        }
        else if (end == start)
        {
            ret = words[start];
            ret.append(maxWidth - len, ' ');
            return ret;
        }
        int cnt = end - start;
        int sp = maxWidth - len;
        int ave = sp / cnt;
        int rem = sp - ave * cnt;
        for (int i = start; i < end; i++)
        {
            ret += words[i];
            ret.append(ave + 1, ' ');
            if (rem)
            {
                ret.append(1, ' ');
                rem--;
            }
        }
        ret += words[end];
        return ret;
    }
    string addLast(vector<string>& words, int start, int end, int maxWidth)
    {
        auto ret = words[start];
        for (int i = start + 1; i <= end; i++)
        {
            ret += " " + words[i];
        }
        if (ret.length() < maxWidth)
        {
            ret.append(maxWidth - ret.length(), ' ');
        }
        return ret;
    }
};
