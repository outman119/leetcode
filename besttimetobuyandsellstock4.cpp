class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
       int len = prices.size();
        if (k == 0 || len == 0)
        {
            return 0;
        }
        if (k >= len)
        {
            return getMaxProfit(prices);
        }
        vector<int>local(k+1, 0);
        vector<int>global(k+1, 0);

        for (int i = 1; i < len; i++) 
        {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; j--) 
            {
                local[j] = max(local[j] + diff, global[j - 1] + max(diff, 0));
                global[j] = max(global[j], local[j]);
            }
        }

        return global[k];
    }
private:
    int getMaxProfit(vector<int>&prices)
    {
        int ma = 0;
        int len = prices.size();
        for (int i = 1; i < len; i++)
        {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0)
            {
                ma += diff;
            }
        }
        return ma;
    }
};
