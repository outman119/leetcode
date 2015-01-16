class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
		 {
			 return "";
		 }
		 string s = strs[0];
		 for (unsigned int i = 1; i < strs.size(); i++)
		 {
			 unsigned int len = s.length();
			 if (len > strs[i].length())
			 {
				 len = strs[i].length();
			 }
			 if (len == 0)
			 {
				 return "";
			 }
			 unsigned int k = 0;
			 for (k = 0; k < len; k++)
			 {
				 if (s[k] != strs[i][k])
				 {
					 break;
				 }
			 }
			 s.erase(k, s.length());
		 }
		 return s;
    }
};
