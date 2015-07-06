class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1)
        {
            return false;
        }
        map<int, int>mm;
        for (int i = 0; i < len; i++)
        {
            if (mm.count(nums[i]) != 0)
            {
                return true;
            }
            mm[nums[i]] = 1;
        }
        return false;
    }
};
