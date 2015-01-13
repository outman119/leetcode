class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int max = n + m-1;
		int i = m-1;
		int j = n-1;
		while (max >= 0 && j>=0 && i >=0)
		{
			if (A[i] > B[j])
			{
				A[max] = A[i];
				i--;
				max--;
			}
			else
			{
				A[max] = B[j];
				j--;
				max--;
			}
		}
		while (j >= 0)
		{
			A[max] = B[j];
			max--;
			j--;
		}
    }
};
