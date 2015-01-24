class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
        {
            return 0;
        }
        int min = prices[0];
        int profit = 0;
        for (unsigned int i = 1; i < prices.size(); i++)
        {
            int minus = prices[i] - min;
            if (prices[i] < min)
            {
                min = prices[i];
            }

            if (profit < minus)
            {
                profit = minus;
            }
        }
        
        return profit;
    }
};
