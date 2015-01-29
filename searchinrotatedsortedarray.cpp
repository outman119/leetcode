class Solution {
public:
    int search(int A[], int n, int target) {
        if (n <= 0)
        {
            return -1;
        }
        int low = 0;
        int high = n - 1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] == target)
            {
                return mid;
            }
            else if (A[mid] > A[low])
            {
                if (A[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    if (A[low] > target)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            else if (A[mid] < A[low])
            {
                if (A[mid] > target)
                {
                    high = mid - 1;
                }
                else
                {
                    if (A[high] < target)
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
            }
            else
            {
                if (A[high] == target)
                {
                    return high;
                }
                else
                {
                    return -1;
                }
            }
        }
        return -1;
    }
};
