class Solution {
public:
    int reverse(int x) {
        if (x == 0)
    	{
    		return x;
    	}
    
    	stringstream ss;
    	ss << x;
    	string   s = ss.str();
    	auto si = s.begin();
    	if (*si == '-')
    	{
    		si++;
    	}
    	std::reverse(si, s.end());
    	long long ret = stoll(s);
    	
    	if (ret > 2147483647 || ret < (-2147483647 - 1))
    	{
    		return 0;
    	}
    	return (int)ret;
    }
};
