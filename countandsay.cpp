class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
		 {
			 return NULL;
		 }
		 string s("1");
		 for (int i = 1; i < n; i++)
		 {
			 auto it = s.begin();
			 int count = 1;
			 ostringstream s1;
			 while (it != s.end())
			 {
				 auto tmp = *it;
				 it++;
				 if (it == s.end())
				 {
					 s1 << count << tmp;
				 }
				 else if (tmp == *it)
				 {
					 count++;
				 }
				 else
				 {
					 s1 << count << tmp;
					 count = 1;
				 }
			 }
			 s = s1.str();
		 }
		 return s;
    }
};
