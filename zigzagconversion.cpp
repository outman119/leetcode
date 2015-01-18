class Solution {
public:
    string convert(string s, int nRows) {
       if (s.length() <= 1 || nRows ==1)
		{
			return s;
		}
		string ret;
		int len = s.length();
		for (int i = 0; i < nRows; i++)
		{
			int j = i;
			bool flag = true;
			while (j < len)
			{
				ret.push_back(s[j]);
				if (i == 0 || i == (nRows - 1))
				{
					
					j += 2 * (nRows - 1);
				}
				else
				{
					if (flag)
					{
						flag = false;
						j += 2 * (nRows - 1 - i);
					}
					else
					{
						flag = true;
						j += 2 * (i);
					}
				}
			}
		}
		return ret; 
    }
};
