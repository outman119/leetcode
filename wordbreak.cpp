class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty() || dict.empty())
		{
			return false;
		}
		int len = s.length();
		vector<bool> dp(len + 1, false);
		dp[0] = true;
		for (int i = 0; i < len; i++)
		{
			if (dp[i])
			{
				for (int j = 1; i + j - 1 < len; j++)
				{
					if (dict.count(s.substr(i, j)) != 0)
					{
						dp[i + j] = true;
					}
				}
			}
		}
		return dp[len];
    }
};
