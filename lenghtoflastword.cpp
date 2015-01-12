class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
    	if (len == 0)
    	{
    		return 0;
    	}
    	int i = 0;
    	for (i = len-1; i >= 0; i--)
    	{
    		if (s[i] != ' ')
    		{
    			break;
    		}
    	}
    	int j = 0;
    	for (j = i; j >= 0; j--)
    	{
    		if (s[j] == ' ')
    		{
    			break;
    		}
    	}
    	return (i - j);
    }
};`
