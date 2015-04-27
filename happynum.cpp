class Solution {
public:
    bool isHappy(int n) {
        int arr[10] = { 0 };
        while (n != 0)
        {
            auto x = n % 10;
            n = n / 10;
            arr[x]++;
        }
        int count = 0;
        for (int i = 1; i < 10; i++)
        {
            if (arr[i] == 0)
            {
                continue;
            }
            count += arr[i]*i*i;
        }
        if (count == 1)
        {
            return true;
        }
        else if (count != 1 && count <10)
        {
            return false;
        }
        else
        {
            return isHappy(count);
        }
    }
};
