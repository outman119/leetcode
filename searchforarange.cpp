class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int>ret(2, -1);
        if (n <= 0 ||
            A[0] > target || 
            A[n - 1] < target)
        {
            return ret;
        }
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {        
            int mid = (low + high) / 2;
            if (A[mid] == target)
            {
                int begin = mid-1, end = mid+1;
                while (begin>= low)
                {
                    if (A[begin] != target)
                    {
                        break;
                    }
                    begin--;
                }
                while (end <= high)
                {
                    if (A[end] != target)
                    {
                        break;
                    }
                    end++;
                }
                ret[0] = begin + 1;
                ret[1] = end - 1;
                break;
            }
            else if (A[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ret;
    }
};
