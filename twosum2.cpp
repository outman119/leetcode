class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        unsigned int i = 0;
        unsigned int j = numbers.size() - 1;
        while (i < j)
        {
            long long sum = numbers[i] + numbers[j];
            if (sum > target)
            {
                j--;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                ret.push_back(i + 1);
                ret.push_back(j + 1);
                break;
            }
        }
        return ret;
    }
		
};
