class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t pos1 = version1.find('.');
    size_t pos2 = version2.find('.');
    size_t pos3 = 0;
    size_t pos4 = 0;
    int flag = 1;
    
    while(flag)
    {
        if(pos1 == string::npos ||
            pos2 == string::npos)
        {
            pos1 = version1.length();
            pos2 = version2.length();
            flag = 0;
            
        }

        string s1(version1,pos3, pos1-pos3);
        string s2(version2,pos4, pos2-pos4);
        if(stof(s1) > stof(s2))
        {
            return 1;
        }
        else if(stof(s1) < stof(s2))
        {
            return -1;
        }
        else if(flag ==0)
        {
            return 0;
        }
        pos3=pos1+1;
        pos4=pos2+1;
        pos1=version1.find('.', pos3);
        pos2=version2.find('.', pos4);
    }

    return 0;
    }
};
