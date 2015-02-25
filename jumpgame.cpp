class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0 || n == 1)
        {
            return true;
        }
        int max = 0;
        for (int i = 0; i < n && i <= max; i++)
        {
            max = (A[i] + i) > max ? (A[i] + i) : max;
        }
        return max >= n - 1;
    }
};
