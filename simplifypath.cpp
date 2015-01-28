class Solution {
public:
    string simplifyPath(string path) {
        if (path.length() <= 1 || path.front() != '/')
        {
            return path;
        }
        stack<string>st;
        string ret;
        
        size_t index = 0, start = 0;
        do
        {
            index = path.find_first_of('/', start);
            if (index != string::npos)
            {
                st.push("/");
                auto sub = path.substr(start, index - start);
                if (!sub.empty())
                {
                    st.push(sub);
                }
                start = index + 1;
                if (start == string::npos) break;
            }
        } while (index != string::npos);
        auto sub = path.substr(start);
        if (!sub.empty())
        {
            st.push(sub);
        }
        while (!st.empty() && st.top() == "/")
        {
            st.pop();
        }
        int count = 0;
        while (!st.empty())
        {
            auto nn = st.top();
            st.pop();
            while (!st.empty() && st.top() == "/")
            {
                st.pop();
            }
            if (nn == "..")
            {
                count++;
            }
            else if (nn == ".")
            {
                continue;
            }
            else
            {
                if (count != 0)
                {
                    count--;
                    continue;
                }
                if (nn != "/")
                {
                    ret = nn + ret;
                }
                
                ret = "/" + ret;
            }
        }
        if (ret.empty())
        {
            ret.insert(0, "/");
        }
        return ret;
    }
};
