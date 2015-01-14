class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int flag = 1;
		auto it = digits.rbegin();
		for (; it != digits.rend(); it++)
		{
			*it = *it + flag;
			flag = 0;
			if (*it >= 10)
			{
				flag = 1;
				*it = *it - 10;
			}
			if (flag == 0)
			{
				break;
			}
		}
		if (flag == 1)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
    }
};
