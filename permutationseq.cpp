class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        vector<int>factors(1,1);
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
            factors.push_back(factors[i - 1] * i);
        }
        string ret;
        auto tmp = n - 1;
        while (n > 0&& k>0)
        {
            auto div = (k - 1) / factors[n-1];
            ret += nums[div] +'0';
            nums.erase(nums.begin() + div);
            k = k - div*factors[n - 1];
            n--;
        }
        return ret;
    }
};
