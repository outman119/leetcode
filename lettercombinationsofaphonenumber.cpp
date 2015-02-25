class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ret;
        if (digits.empty())
        {
            return ret;
        }
        string ss;
        int index = 0;
        getCom(digits, index, ss, ret);
        return ret;
    }
private:
    void getCom(string digits, int index, string &ss, vector<string>&ret)
    {
        if (digits.empty())
        {
            return;
        }
        if (ss.length() == digits.length())
        {
            ret.push_back(ss);
            return;
        }
        for (int i = index; i < digits.length(); i++)
        {
            vector<char>tmp;
            getVectorByChar(digits[i], tmp);
            for (int j = 0; j < tmp.size(); j++)
            {
                ss.push_back(tmp[j]);
                getCom(digits, i+1, ss, ret);
                ss.pop_back();
            }
        }
        return;
    }
    void getVectorByChar(char c, vector<char>&tmp)
    {
        tmp.clear();
        if (c <'2' || c >'9')
        {
            return;
        }
        switch (c)
        {
        case '2':
            tmp.push_back('a');
            tmp.push_back('b');
            tmp.push_back('c');
            break;
        case '3':
            tmp.push_back('d');
            tmp.push_back('e');
            tmp.push_back('f');
            break;
        case '4':
            tmp.push_back('g');
            tmp.push_back('h');
            tmp.push_back('i');
            break;
        case '5':
            tmp.push_back('j');
            tmp.push_back('k');
            tmp.push_back('l');
            break;
        case '6':
            tmp.push_back('m');
            tmp.push_back('n');
            tmp.push_back('o');
            break;
        case '7':
            tmp.push_back('p');
            tmp.push_back('q');
            tmp.push_back('r');
            tmp.push_back('s');
            break;
        case '8':
            tmp.push_back('t');
            tmp.push_back('u');
            tmp.push_back('v');
            break;
        case '9':
            tmp.push_back('w');
            tmp.push_back('x');
            tmp.push_back('y');
            tmp.push_back('z');
            break;
        default:
            break;
        }
        return;
    }
}
