class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0)
    	{
    		return 0;
    	}
    	int count = n;
    
    	int i = 0;
    	int j = n - 1;
    	while (i < j)
    	{
    		if (A[i] != elem)
    		{
    			i++;
    		}
    		else if (A[j] == elem)
    		{
    			j--;
    			count--;
    		}
    		else
    		{
    			A[i] = A[j];
    			j--;
    			i++;
    			count--;
    		}
    	}
    	if (i == j)
    	{
    		if (A[i] == elem)
    		{
    			count--;
    		}
    	}
    	return count;

    }
};
