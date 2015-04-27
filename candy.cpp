class Solution {
public:
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        vector<int>give(len, 1);

        for (int i = 1; i < len;i++)
        {
            if (ratings[i] >  ratings[i - 1])
            {
                give[i] = give[i - 1] + 1;;
            }
        }
        for (int i = len - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && give[i]<=give[i+1])
            {
                give[i] = give[i + 1]+1;
            }
        }
        int sum = 0;
        for (auto x : give)
        {
            sum += x;
        }
        return sum;
    }
};
