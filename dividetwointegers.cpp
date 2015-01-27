class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
        {
            return INT_MAX;
        }
        if (dividend == 0)
        {
            return 0;
        }
        int flag = 0;
        if (dividend < 0)
        {
            flag++;
        }
        if (divisor < 0)
        {
            flag++;
        }
        long long n1 = abs((long long)dividend);
        long long n2 = abs((long long)divisor);
        long long result = 0;
        while (n1 >= n2)
        {
            long long base = n2;
            for (int i = 0; base <= n1; i++)
            {
                n1 = n1 - base;
                base = base << 1;
                result += 1LL << i;
            }
        }
        if (flag == 1)
        {
            result *= -1;
        }
        if (result > INT_MAX || result < INT_MIN)
        {
            return INT_MAX;
        }
        return (int)result;
    }
};
