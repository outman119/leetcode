class Solution {
public:
    string minWindow(string S, string T) {
        int len1 = S.length();
        int len2 = T.length();
        string ret;
        if (len1 < len2)
        {
            return ret;
        }
        map<char, int>mm;
        map<char, int>cc;
        int sum = 0;
        for (int i = 0; i < len2; i++)
        {
            mm[T[i]]++;
            sum++;
        }
        queue<pair<char,int>>que;
        int start = 0;
        int minlen = len1+1;
        auto count = 0;
        auto last = 0;
        bool find = false;
        for (int i = 0; i < len1; i++)
        {
            if (mm.count(S[i]) == 0)
            {
                continue;
            }
            last = i;
            auto tmp = S[i];
            auto pp = make_pair(tmp, i ) ;
            que.push(pp);
            cc[tmp]++;
            if (cc[tmp] > mm[tmp])
            {
                continue;
            }
            count++;
            while (count == sum)
            {
                find = true;
                auto pp = que.front();
                que.pop();
                if (minlen > i - pp.second+1)
                {
                    minlen = i - pp.second+1;
                    start = pp.second;
                }
                
                if (cc[pp.first] <= mm[pp.first])
                {
                    count--;
                }
                cc[pp.first]--;
            }
           
        }
        while (count == sum)
        {
            auto pp = que.front();
            que.pop();
            if (minlen > last - pp.second+1)
            {
                minlen = last - pp.second+1;
                start = pp.second;
            }

            if (cc[pp.first] <= mm[pp.first])
            {
                count--;
            }
            cc[pp.first]--;
        }
        if (find)
        {
            return S.substr(start, minlen);
        }
        else
        {
            return string();
        }
    }
};
