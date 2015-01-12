class Solution {
public:
    int strStr(char *haystack, char *needle) {
    	int len = strlen(haystack);
    	int slen = strlen(needle);
    	if (slen == 0)
    	{
    		return 0;
    	}
    	if (slen >len)
    	{
    		return -1;
    	}
    	int i = 0;
    	int j = 0;
    	for (i = 0; i < len-slen +1; i++)
    	{
    		if (haystack[i] == needle[0])
    		{
    			int flag = 0;
    			for (j = 1; (j < slen) && (j + i <len); j++)
    			{
    				if (haystack[j + i] != needle[j])
    				{
    					flag = 1;
    					break;
    				}
    			}
    			if (flag == 0 && j == slen)
    			{
    				return i;
    			}
    		}
    	}
    	return -1;
    }
};
