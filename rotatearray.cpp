class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (n == 0 || k == 0 || k % n ==0)
        {
            return;
        }
        k = k%n;
        rotateArray(nums, 0, n - k-1);
        rotateArray(nums, n - k, n-1);
        rotateArray(nums, 0, n - 1);
        return;
    }
private:
    void rotateArray(int nums[], int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};
