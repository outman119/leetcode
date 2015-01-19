class Solution {
public:
    static bool new_cmp(string a, string b)
	{
		return (a + b) > (b + a);
	}
	string largestNumber(vector<int> &num) {
		if (num.size() ==0)
		{
			return NULL;
		}
		vector<string>s;
		for (auto it = num.begin(); it != num.end(); it++)
		{
			s.push_back(to_string(*it));
		}
		sort(s.begin(), s.end(), new_cmp);
		string ret;
		for (auto it = s.begin(); it != s.end(); it++)
		{
			ret += *it;
		}
		if (ret[0] == '0')
			return "0";
		return ret;
	}
};
