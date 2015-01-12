class Solution {
public:
    string addBinary(string a, string b) {
        string s;
    	int al = a.length();
    	int bl = b.length();
    	auto ai = a.rbegin();
    	auto bi = b.rbegin();
    	int flag = 0;
    	while (ai != a.rend() && bi != b.rend())
    	{
    		int ad = *ai - '0';
    		int bd = *bi - '0';
    		int c = ad + bd + flag;
    		if (c == 3)
    		{
    			s.push_back('1');
    			flag = 1;
    		}
    		else if (c == 2)
    		{
    			s.push_back('0');
    			flag = 1;
    		}
    		else if (c == 1)
    		{
    			s.push_back('1');
    			flag = 0;
    		}
    		else
    		{
    			s.push_back('0');
    			flag = 0;
    		}
    		ai++;
    		bi++;
    	}
    	while (ai != a.rend())
    	{
    		if (flag == 0)
    		{
    			s.push_back(*ai);
    		}
    		else
    		{
    			if (*ai == '1')
    			{
    				s.push_back('0');
    				flag = 1;
    			}
    			else
    			{
    				s.push_back('1');
    				flag = 0;
    			}
    		}
    		ai++;
    	}
    	while (bi != b.rend())
    	{
    		if (flag == 0)
    		{
    			s.push_back(*bi);
    		}
    		else
    		{
    			if (*bi == '1')
    			{
    				s.push_back('0');
    				flag = 1;
    			}
    			else
    			{
    				s.push_back('1');
    				flag = 0;
    			}
    		}
    		bi++;
    	}
    	if (flag == 1)
    	{
    		s.push_back('1');
    	}
    	reverse(s.begin(), s.end());
    	return s;
    }
};
