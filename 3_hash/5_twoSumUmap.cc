#include <iostream>
#include <vector>
#include <unordered_map>

using std::pair;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    // 假设nums=[2,7,11,15] target=9
    // umap为空
    // it = umap.find(9-2)
    // 加入umap 即[(2, 0)]
    // it = umap.find(9-7)
    // 返回0, 1
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // k是nums[i] v是i
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = umap.find(target - nums[i]);
            // 找到了
            if (it != umap.end())
            {
                return {it->second, i};
            }
            umap.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main()
{
    return 0;
}