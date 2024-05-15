#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 定义为[）
        int low = 0;
        int high = nums.size();
        int mid;
        // 定义为闭区间[）, low = high时[]不合法, 因此<
        while (low < high)
        {
            // mid = (low + high) / 2;
            mid = low + (high - low) / 2;
            // ---------------------
            //           ^         ^
            //         mid    target
            if (nums[mid] < target)
            {
                // 左闭
                low = mid + 1;
            }
            // ---------------------
            // ^         ^
            // target    mid
            else if (nums[mid] >= target)
            {
                // 右开
                high = mid;
            }
        }
        // 找到目标值
        if (low < nums.size() && nums[low] == target)
        {
            return low;
        }
        return -1;
    }
};