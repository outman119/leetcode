class Solution {
public:
vector<int> getRow(int rowIndex) {
    if (rowIndex < 0)
	{
		return vector<int>();
	}
	vector<int> level;
	for (int i = 0; i <= rowIndex; i++)
	{
		int l = level.size();
		for (int j = l-1; j >=1; j--)
		{
			level[j] += level[j - 1];
		}
		level.push_back(1);
	}
	return level;
    }
};
