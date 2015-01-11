class Solution {
public:
    bool isPalindrome(string s) {
    if (s.empty())
	{
		return true;
	}
	string s1;
	for (auto is = s.begin(); is != s.end(); is++)
	{
		if (isalpha(*is))
		{
			s1 += tolower(*is);
		}
		if (isdigit(*is))
		{
			s1 += *is;
		}
	}
	string s2(s1);
	reverse(s2.begin(), s2.end());
	return (s1.compare(s2) ==0);
    }
};
