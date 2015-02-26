class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n == 0 || A == NULL)
        {
            return 1;
        }
        int min = 0;
        int max = 0;
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (A[i]>0)
            {
                min = A[i];
                max = A[i];
                break;
            }
        }
        for (; i < n; i++)
        {
            if (A[i] <= 0)
            {
                continue;
            }
            if (A[i] < min)
            {
                min = A[i];
            }
            if (A[i] > max)
            {
                max = A[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (A[i] <= 0)
            {
                continue;
            }
            else if (A[i] - min != i)
            {
                while (A[i] != min + i)
                {
                    if (A[i] <= 0)
                    {
                        break;
                    }
                    //swap
                    int j = A[i] - min;
                    if (j >= n)
                    {
                        break;
                    }
                    else if (A[j] == A[i])
                    {
                        break;
                    }
                    else
                    {
                        swap(A[i], A[j]);
                    }
                }

            }
        }
        for (int i = 0; i < n; i++)
        {
            if (A[i] != i + 1)
            {
                return i + 1;
            }
        }
        return max + 1;
    }
};
