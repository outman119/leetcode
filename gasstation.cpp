class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() != cost.size() ||
			gas.size() == 0)
		{
			return -1;
		}
		int max = 0;
		int index = 0;
		int total = 0;
		for (unsigned int i = 0; i < gas.size(); i++)
		{
			int diff = gas[i] - cost[i];
			total += diff;
			if (max < 0)
			{
				max = diff;
				index = i;
			}
			else
			{
				max = max + diff;
			}
		}
		if (total >= 0)
		{ 
			return index;
		}
		else
		{
			return -1;
		}
    }
};
