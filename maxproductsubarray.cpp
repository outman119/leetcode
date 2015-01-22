class Solution {
public:
    int maxProduct(int A[], int n) {
     if (n == 0)
        {
            return 0;
        }
        int lmax = A[0];
        int lmin = A[0];
        int ret = A[0];
        for (int i = 1; i < n; i++)
        {
            int tmp1 = lmax * A[i];
            int tmp2 = lmin * A[i];
            lmax = max(max(tmp1, tmp2), A[i]);
            lmin = min(min(tmp1, tmp2), A[i]);
            ret = max(ret, lmax);
        }
        return ret;
    }
private:
    int max(int a, int b)
    {
        return a>b ? a : b;
    }
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
};
