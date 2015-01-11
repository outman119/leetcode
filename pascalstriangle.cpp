class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if (numRows <= 0)
    	{
    		return vector<vector<int> >();
    	}
    	vector<vector<int> > ret;
    	vector<int> level;
    	for (int i = 1; i <= numRows; i++)
    	{
    		int l = level.size();
    		for (int j = l-1; j >=1; j--)
    		{
    			level[j] += level[j - 1];
    		}
    		level.push_back(1);
    		ret.push_back(level);
    	}
    	return ret;
    }
};
