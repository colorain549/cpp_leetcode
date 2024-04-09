// 输出
// 4
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        // [left, right]
        // [1, 1]合法
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > target)
            {
                // [target mid]
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                // [mid target]
                low = mid + 1;
            }
            else
            {
                // 目标值存在
                return mid;
            }
        }
        return -1;
    }
};

int main()
{
    int result;

    vector<int> nums{-1, 0, 3, 5, 9, 12};

    int target = 9;

    Solution solution;
    result = solution.search(nums, target);

    cout << result << endl;

    return 0;
}