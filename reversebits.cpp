class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint64_t rr = 0;
        uint32_t count = 1;
        uint64_t cc = pow(2, 31);;
        for (int i = 0; i < 32; i++)
        {
            if ((n&count) != 0)
            {
                rr += cc;
            }
            count *= 2;
            cc /= 2;
        }
        if (rr > UINT32_MAX)
        {
            return 0;
        }
        return (uint32_t)rr;
    }
};
