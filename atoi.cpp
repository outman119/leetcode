class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL || str=="\0")
		{
			return 0;
		}
		long long ret = 0;
		bool neg_flag = 0;
		for (; isspace(*str); str++);
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
			{
				neg_flag = true;
			}
			str++;
		}
		for (; isdigit(*str); str++)
		{
			ret = ret * 10 + *str - '0';
			if ((neg_flag == false && ret > 2147483647))
			{
				return 2147483647;
			}
			else if ((neg_flag == true && ret > (2147483648)))
			{
				return -2147483648;
			}
		}
		return neg_flag?(int)(-1)*ret:(int)ret;
    }
};
