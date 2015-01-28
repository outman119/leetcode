class Solution {
public:
    int sqrt(int x) {
        if (x <= 1)
        {
            return x;
        }
        uint64_t begin = 1;
        uint64_t end = x / 2;
        uint64_t mid = (begin + end) / 2;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            if (mid*mid == x)
            {
                return mid;
            }
            else if (mid*mid > x)
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }

        }
        return (int)end;
    }
};
