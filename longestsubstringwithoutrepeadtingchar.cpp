class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len <= 1)
        {
            return len;
        }
        int max = 1;
        int count = 1;
        int start = 0;
        for (int i = 1; i < len; i++)
        {
            bool flag = false;
            for (int j = start; j < i; j++)
            {
                if (s[j] == s[i])
                {
                    start = j + 1;
                    max = max > count ? max : count;
                    count = i-j;
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                count++;
            }
        }
        max = max > count ? max : count;
        return max;
    }
};
