#include <iostream>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 收集结果容器
        vector<vector<int>> result;
        // 记得先排序
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++)
            {
                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};