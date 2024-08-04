#include <iostream>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 1221=>12
        // 22与12比较=>2
        // rset用于保存结果
        unordered_set<int> rset;
        // 1221映射到uset后变成12
        unordered_set<int> uset(nums1.begin(), nums1.end());
        // nums2中的元素是否在nums1/uset中出现
        // for (int num : nums2)
        for (const auto &num : nums2)
        {
            if (uset.find(num) != uset.end())
            {
                rset.insert(num);
            }
        }
        // 注意需强制转换
        return vector<int>(rset.begin(), rset.end());
    }
};