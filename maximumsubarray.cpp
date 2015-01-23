class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
		int global = A[0];
		for (int i = 0; i < n; i++)
		{
			sum += A[i];
			global = global > sum ? global : sum;
			if (sum < 0)
			{
				sum = 0;
			}
			
		}
		return global;
    }
};
