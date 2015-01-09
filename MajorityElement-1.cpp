class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 0;
        int ele=0;
        for(auto item = num.begin();item<num.end();item++)
        {
            if(count==0)
            {
                ele=*item;
                count=1;
            }
            else
            {
                if(ele!=*item)
                {
                    count --;
                }
                else
                {
                    count++;
                }
            }
        }
        return ele;
    }
};
