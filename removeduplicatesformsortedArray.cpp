class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)
		 {
			 return n;
		 }
		 int i = 0;
		 int index = 0;
		 for (i = 0; i < n-1; i++)
		 {
			 if (A[i] != A[i + 1])
			 {
				 A[++index] = A[i+1];
			 }
		 }
		 return index + 1;
    }
};
