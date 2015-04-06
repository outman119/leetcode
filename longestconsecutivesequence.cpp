class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int len = num.size();
        map<int, int>mm;
        for (auto x : num)
        {
            mm[x] = 1;
        }
        int count = 1;
        int max = 1;
        for (auto x : num)
        {
            if (mm.count(x) == 0)
            {
                continue;
            }
            auto y = x + 1;
            auto z = x - 1;
            count = 1;
            while (mm.count(y) != 0)
            {
                count++; 
                mm.erase(y);
                y++;
            }
            while (mm.count(z) != 0)
            {
                count++; 
                mm.erase(z);
                z--;
            }
            mm.erase(x);
            if (count > max)
            {
                max = count;
            }
        }
        return max;
    }
};
