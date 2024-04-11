#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

//
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        // 1 dp数组及其下标含义
        // dp[i]对应斐波那契数列第i个元素
        vector<int> dp(n + 1);

        // 2 递归公式
        // dp[i] = dp[i-1] + dp[i-2];

        // 3 dp数组初始化
        dp[0] = 0;
        dp[1] = 1;

        // 4 遍历顺序(从左到右)
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];

        // 5 debug
    }
};

int main()
{
    return 0;
}