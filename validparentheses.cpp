class Solution {
public:
    bool isValid(string s) {
      if (s.empty())
		 {
			 return true;
		 }
		 stack<char> s1;
		 for (auto it = s.begin(); it != s.end(); it++)
		 {
			 if (*it == '{' || *it == '[' || *it == '(')
			 {
				 s1.push(*it);
			 }
			 else if (*it == '}' || *it == ']' || *it ==')')
			 {
				 if (s1.empty())
				 {
					 return false;
				 }
				 if ((*it == '}' && s1.top() == '{') ||
					 (*it == ']' && s1.top() == '[') ||
					 (*it == ')' && s1.top() == '('))
				 {
				     s1.pop();
					 continue;
				 }
				 else
				 {
					 return false;
				 }
			 }
		 }
		 if (s1.empty())
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }
};
