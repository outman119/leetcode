class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int>ret;
		vector<int>nn(numbers);
		sort(nn.begin(), nn.end());
		int len = nn.size();
		int i = 0;
		int j = len-1;
		while(i < j)
		{
			int sum = nn[i] + nn[j];
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
				ret = vectorFind(numbers, nn[i], nn[j]);
				break;
			}
		}
		return ret;

	}
private:
	vector<int> vectorFind(vector<int>num, int tt1, int tt2)
	{
		vector<int> ret;
		for (unsigned int i = 0; i < num.size(); i++)
		{
			if (num[i] == tt1)
			{
				ret.push_back(i + 1);
			}
			else if (num[i] == tt2)
			{
				ret.push_back(i + 1);
			}
		}
		return ret;
	}
};
