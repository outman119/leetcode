class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for (int i = 1; i < num.size(); i++)
		{
			if (num[i - 1] > num[i])
			{
				return i - 1;
			}
		}
		return num.size()-1;
    }
};
