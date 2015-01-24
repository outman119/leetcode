class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int ret = 0;
        if (n <= 0)
        {
            return 0;
        }
        if (target > A[n - 1])
        {
            return n;
        }
        else if (target == A[n - 1])
        {
            ret = n - 1;
        }
        else if (target <= A[0])
        {
            return 0;
        }
        int low = 0;
        int high = n - 1;
        int mid = 0;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (A[mid] == target)
            {
                return mid;
            }
            else if (A[mid]>target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if(A[low] < target)
        {
            return low +1;
        }
        else
        {
            return low;
        }
    }
};
