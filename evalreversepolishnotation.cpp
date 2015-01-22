class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int ret = 0;
        if (tokens.size() == 0)
        {
            return ret;
        }
        stack<int> st;
        for (auto it = tokens.begin(); it != tokens.end(); it++)
        {
            if (*it == "+" ||
                *it == "-" ||
                *it == "*" ||
                *it == "/")
            {
                if (st.size() < 2)
                {
                    return 0;
                }
                int tmp1 = st.top();
                st.pop();
                int tmp2 = st.top();
                st.pop();
                int ret = getResult(tmp2, tmp1, *it);
                st.push(ret);
            }
            else
            {
                st.push(stoi(*it));
            }
        }
        if (st.size() != 1)
        {
            return 0;
        }
        return st.top();
    }
private:
    int getResult(int a, int b, string it)
    {
        if (it == "+")
        {
            return a + b;
        }
        if (it == "-")
        {
            return a - b;
        }
        if (it == "*")
        {
            return a*b;
        }
        if (it == "/")
        {
            if (b == 0)
            {
                return 0;
            }
            return a / b;
        }
    }
};
