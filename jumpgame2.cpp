class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0 || n == 1)
        {
            return 0;
        }
        int currmax = A[0];
        int lastmax = currmax;
        int jump = 1;
        for (int i = 1; i < n; i++)
        {

            if (i > currmax)
            {
                return -1;
            }
            if (i > lastmax)
            {
                jump++;
                lastmax = currmax;
            }
            currmax = max(currmax, A[i] + i);
            
        }
        return jump;
    }
};
