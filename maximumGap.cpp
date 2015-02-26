class Solution {
public:
    int maximumGap(vector<int> &num) {
      if (num.size() < 2)
        {
            return 0;
        }
        int max = *max_element(num.begin(), num.end());
        int min = *min_element(num.begin(), num.end());

        int div = (max - min) / (num.size() - 1) +1;
        int count = (max - min) / (div) +1;
        vector<pair<int, int>>bucket(count, make_pair(INT_MAX, INT_MIN));
        for (auto val : num)
        {
            int n = (val - min) / div;
            if (val < bucket[n].first)
            {
                bucket[n].first = val;
            }
            if (val > bucket[n].second)
            {
                bucket[n].second = val;
            }
        }
        int maxGap = bucket[0].second - bucket[0].first;
        int lastMax = min;
        for (auto b : bucket)
        {
            if (b.first == INT_MAX)
            {
                continue;
            }
            int curMax = b.second;
            int curMin = b.first;
            maxGap = maxInt(maxGap, curMin - lastMax);
            lastMax = curMax;
        }
        return maxGap;
    }
private:
    int maxInt(int a, int b)
    {
        return a > b ? a : b;
    }  
};
