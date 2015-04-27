class Solution {
public:
    int dna['T' + 1];
    char rdna[4];
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ret;
        dna['A'] = 0;
        dna['C'] = 1;
        dna['G'] = 2;
        dna['T'] = 3;
        rdna[0] = 'A';
        rdna[1] = 'C';
        rdna[2] = 'G';
        rdna[3] = 'T';
        int len = s.length();
        if (len < 9)
        {
            return ret;
        }
        map<unsigned int, int>mm;
        unsigned int x = 0;
        unsigned int k = 1000000000;
        for (int i = 0; i < 10; i++)
        {
            x += dna[s[i]] * k;
            k /= 10;
        }
        mm[x] = 1;
        k = 1000000000;
        for (int i = 1; i < len - 9; i++)
        {
            x -= dna[s[i - 1]] * k;
            x *= 10;
            x += dna[s[i + 9]];
            if (mm[x]==1)
            {
                string ss(10, ' ');
                auto y = x;
                for (int j = 9; j >= 0; j--)
                {
                    ss[j] = rdna[y % 10];
                    y /= 10;
                }
                ret.push_back(ss);
            }
            mm[x]++;
        }
        return ret;
    }
};
