class Solution {
public:
    string intToRoman(int num) {
        string ret;
        if (num < 1 || num>3999)
        {
            return ret;
        }
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
        {
            while (num >= values[i])
            {
                num -= values[i];
                ret += roman[i];
            }
        }
        return ret;
    }
};
