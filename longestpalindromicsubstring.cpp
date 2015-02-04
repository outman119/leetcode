class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len <= 1)
        {
            return s;
        }
        int start = 0;
        int maxlen = 1;
        for (int i = 0; i < len-1; i++)
        {
            auto len1 = getMaxlen(s, i, i);
            auto len2 = getMaxlen(s, i, i + 1);
            if (len1 > maxlen)
            {
                maxlen = len1;
                start = i - (len1 - 1) / 2;
            }
            if (len2 > maxlen)
            {
                maxlen = len2;
                start = i - len2 / 2 + 1;
            }
        }
        return s.substr(start, maxlen);
    }
private:
    int getMaxlen(string s, int left, int right)
    {
        int len = s.length();
        while (left >= 0 && right <= len - 1 && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
