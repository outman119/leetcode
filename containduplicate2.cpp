class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0 || len == 1)
        {
            return false;
        }
        map<int, int>mm;
        for (int i = 0; i < len; i++)
        {
            if (mm.count(nums[i]) != 0 && (i- mm[nums[i]] <= k) )
            {
                return true;
            }
            mm[nums[i]] = i;
        }
        return false;
    }
};
