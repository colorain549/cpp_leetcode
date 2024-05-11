// 输出
// 2
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::vector;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 保存符合条件的最小的子数组的长度
        int result = INT32_MAX;
        // 滑动窗口元素之和
        int sum = 0;
        // 滑动窗口长度
        int subLength = 0;
        // 滑动窗口开始端
        int i = 0;
        // 滑动窗口末端
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                subLength = j - i + 1;
                result = min(result, subLength);
                sum -= nums[i];
                i++;
            }
        }
        // 若result存在则返回result
        // 否则返回0
        return result == INT32_MAX ? 0 : result;
    }
};

int main()
{
    int target = 7;
    vector<int> nums{2, 3, 1, 2, 4, 3};

    Solution solution;
    int ret = solution.minSubArrayLen(target, nums);

    cout << ret << endl;

    return 0;
}