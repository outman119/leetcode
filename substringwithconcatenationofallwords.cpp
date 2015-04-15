class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L) {
        vector<int>res;
        int len = S.length();
        int lena = L.size();
        if (lena == 0)
        {
            return res;
        }
        int lenb = L[0].length();
        int len1 = lena * lenb;
        if (len < len1)
        {
            return res;
        }
        map<string, int>mm;
        map<string, int>cc;
        for (auto x : L)
        {
            mm[x]++;
        }
        for (int i = 0; i <= len - len1; i++)
        {
            cc.clear();
            int j = 0;
            for (j = 0; j < lena;j++)
            { 
                auto ss = S.substr(i + j*lenb, lenb);
                cc[ss]++;
                if (cc[ss] > mm[ss])
                {
                    break;
                }
            }
            if (j == lena)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
