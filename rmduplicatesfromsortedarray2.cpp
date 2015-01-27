class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)
        {
            return n;
        }
        int value = A[0];
        int count = 1;
        int j = 1;
        for (int i = 1; i < n; i++)
        {
            if (A[i] != value)
            {
                count = 1;
                value = A[i];
                A[j] = A[i];
                j++;
            }
            else
            {
                count++;
                if (count > 2)
                {
                    continue;
                }
                else
                {
                    A[j] = A[i];
                    j++;
                }
            }
        }
        return j;
    }
};
