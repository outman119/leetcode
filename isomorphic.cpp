class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if (len1 != len2)
        {
            return false;
        }
        map<char, char>mm;
        map<char, char>mn;
        for (int i = 0; i < len1; i++)
        {
            auto sc = s[i];
            auto tc = t[i];
            if (mm.find(sc) != mm.end() && mm[sc] != tc)
            {
                return false;
            }

            if (mn.find(tc) != mn.end() && mn[tc] != sc)
            {
                return false;
            }
            mm[sc] = tc;
            mn[tc] = sc;
        }
        return true;
    }
};
