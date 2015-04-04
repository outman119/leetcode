Î×class Solution {
public:
    int rob(vector<int> &num) {
        int size = num.size();
        if (size == 0)
        {
            return 0;
        }
        vector<int>rob0(size, 0);
        vector<int>rob1(size, 0);
        rob0[0] = 0;
        rob1[0] = num[0];
        for (int i = 1; i < size; i++)
        {
            rob0[i] = max(rob1[i - 1], rob0[i-1]);
            rob1[i] = rob0[i - 1] + num[i];
        }

        return max(rob0[size - 1], rob1[size - 1]);
    }
};
