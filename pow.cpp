class Solution {
public:
    double pow(double x, int n) {
        if (n == 0)
        {
            return 1.0;
        }
        if (n < 0)
        {
            if(n == INT_MIN)
            {
                return 1/(pow(x, INT_MAX)*x);
            }
            else
            {
                return 1 / pow(x, -n);
            }
        }
        double v = pow(x, n / 2);
        if (n % 2 == 0)
        {
            return v*v;
        }
        else
        {
            return v*v*x;
        }
    }
};
