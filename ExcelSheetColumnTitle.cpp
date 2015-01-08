class Solution {
public:
    string convertToTitle(int n) {
        string str;
        while (n)
        {   
            char c ;
            if(n%26!=0)
            {
                c= n%26 +'A'-1;
            }
            else
            {
                c='Z';
            }
            str.insert(0, 1, c);
            n=(n-1)/26;
        }
        return str;
        
    }
};
