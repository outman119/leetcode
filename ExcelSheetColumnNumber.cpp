class Solution {
public:
    int titleToNumber(string s) {
        int num=0;
        int i = 1;
        for (auto rit=s.crbegin(); rit!=s.crend(); ++rit)
        {
            num+=(*rit-'A'+1)*i;
            i=i*26;
        }
        return num;
    }
};
