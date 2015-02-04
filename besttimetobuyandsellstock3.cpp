class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
        {
            return 0;
        }
        int len = prices.size();
        vector<int>pro1(len);
        vector<int>pro2(len);
        int minp = prices[0];
        pro1[0] = 0;
        for (int i = 1; i < len; i++)
        {
            minp = std::min(minp, prices[i]);
            pro1[i] = std::max(pro1[i - 1], prices[i] - minp);
        }
        pro2[len - 1] = 0;
        int maxp = prices[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            maxp = std::max(maxp, prices[i]);
            pro2[i] = std::max(pro2[i + 1], maxp - prices[i]);
        }
        maxp = 0;
        for (int i = 0; i < len; i++)
        {
            maxp = std::max(maxp, pro1[i] + pro2[i]);
        }
        return maxp;
    }
};
