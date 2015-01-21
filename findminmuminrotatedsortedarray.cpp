class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 0)
		{
			return 0;
		}
		if (num.size()==1)
		{
			return num[0];
		}
		int len = num.size();
		int low = 0;
		int high = len - 1;
		int mid = 0;
		while (low < high)
		{
			mid = (low + high)/2;
			if (low == mid)
			{
				return num[low] > num[high] ? num[high] : num[low];
			}
			if (num[low] < num[mid] && num[mid] < num[high])
			{
				high = mid;
			}
			else if (num[low] < num[mid] && num[mid] > num[high])
			{
				low = mid;
			}
			else if (num[low] > num[mid])
			{
				high = mid;
			}
		}
		return num[mid];
    }
};
