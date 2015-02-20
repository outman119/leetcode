class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty())
        {
            return false;
        }
        int l = matrix.size();
        return search(matrix, target, 0, l-1);
    }
private:
    bool search(vector<vector<int> > &matrix, int target, int start, int end)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if (start > end ||
            start < 0 ||
            end >= m)
        {
            return false;
        }
        if (start == end)
        {
            return search(matrix[start], target);
        }
        int mid = (start + end) / 2;
        if (matrix[mid][n - 1] == target)
        {
            return true;
        }
        else if (matrix[mid][n - 1] > target)
        {
            return search(matrix, target, start, mid);
        }
        else
        {
            return search(matrix, target, mid+1, end);
        }
        return false;
    }
    bool search(vector<int>&matrix, int target)
    {
        if (matrix.empty())
        {
            return false;
        }
        int len = matrix.size();
        if (target < matrix[0] || target > matrix[len - 1])
        {
            return false;
        }
        int start = 0;
        int end = len - 1;
        int mid = 0;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (matrix[mid] == target)
            {
                return true;
            }
            else if (matrix[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
};
