#include <iostream>
#include <unordered_set>

using std::unordered_set;

class Solution
{
private:
    int getSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n)
    {
        unordered_set<int> uset;
        // 注意sum==1需放在循环内
        // 注意不要忘记else{uset.insert(sum);}
        // 注意n==sum需放在循环内
        while (1)
        {
            int sum = getSum(n);
            if (sum == 1)
            {
                return true;
            }
            if (uset.find(sum) != uset.end())
            {
                return false;
            }
            else
            {
                uset.insert(sum);
            }
            n = sum;
        }
    }
};