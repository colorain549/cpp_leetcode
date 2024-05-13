#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // 统计a+b出现的次数 k是a+b v是出现的频率
        unordered_map<int, int> umap;
        for (const auto &elem1 : nums1)
        {
            for (const auto &elem2 : nums2)
            {
                umap[elem1 + elem2]++;
            }
        }
        // 统计0-(c+d)出现的次数
        int count = 0;
        for (const auto &elem3 : nums3)
        {
            for (const auto &elem4 : nums4)
            {
                if (umap.find(0 - (elem3 + elem4)) != umap.end())
                {
                    // 加上 对应的(a+b) 出现的频率
                    count += umap[0 - (elem3 + elem4)];
                }
            }
        }
        return count;
    }
};