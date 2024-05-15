#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

using std::cout;
using std::endl;

class Solution
{
public:
    class MyCompare
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            // 小顶堆
            return lhs.second > rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 先用umap统计nums中元素出现的频率
        // k是nums[i], v是频率
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }

        // 声明优先级队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> pque;
        // 往优先级队列添加元素
        unordered_map<int, int>::iterator it;
        for (it = umap.begin(); it != umap.end(); it++)
        {
            pque.push(*it);
            // 只维护k个元素的优先级队列
            if (pque.size() > k)
            {
                pque.pop();
            }
        }

        // 最终结果
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            //  result[i] (1-3)(2-2)(3-1)
            //         i   0    1
            // first是umap[i]即元素, second是频率
            result[i] = pque.top().first;
            // cout << "[" << pque.top().first << "-" << pque.top().second << "]" << endl;
            pque.pop();
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution solution;
    solution.topKFrequent(nums, k);

    return 0;
}