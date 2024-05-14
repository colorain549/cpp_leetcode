#include <iostream>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        // 先排序
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            // a已经大于0, a<b<c
            // a+b+c不可能 = 0
            if (nums[i] > 0)
            {
                return result;
            }
            // !!!对a进行去重(需加深理解)
            // 不要忘记这段代码
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // 双指针法
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // !!!对bc进行去重(注意都是while循环)
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    // 接下来退出循环(注意这段代码的位置)
                    // -1 -2 -2 3 3
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};