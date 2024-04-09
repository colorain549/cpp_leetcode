// 输出
// 5
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            // 当快指针没有指向要删的值
            if (nums[fast] != val)
            {
                // 覆盖
                nums[slow] = nums[fast];
                // 慢指针移动
                slow++;
            }
        }
        return slow;
    }
};

int main()
{
    int result;

    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    Solution solution;
    result = solution.removeElement(nums, val);

    cout << result << endl;

    return 0;
}