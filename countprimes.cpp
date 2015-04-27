class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
        {
            return 0;
        }
        vector<bool>prime(n, false);
        int count = n-2;
        prime[0] = false;
        prime[1] = false;
        prime[2] = true;
        for (int i = 3; i < n; i++)
        {
            prime[i] = i % 2 != 0;
        }
        if (n & 0x1)
        {
            count = count - count / 2 ;
        }
        else
        {
            count = count - count / 2 + 1;
        }
        int sq = sqrt(n);
        for (int i = 3; i <= sq; i+=2)
        {
            if (prime[i])
            {
                for (int j = i*i; j < n; j += 2*i)
                {
                    if (prime[j] == false)
                    {
                        continue;
                    }
                    prime[j] = false;
                    count--;
                }
            }
        }

        return count;
    }
};
