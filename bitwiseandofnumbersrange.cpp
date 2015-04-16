class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int maxx = 2147483647;
        while ((m&maxx) != (n&maxx))
        {
            maxx <<= 1;
        }
        return m&maxx;
    }
};
