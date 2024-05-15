// nums = [1,3,-1,-3,5,3,6,7], k = 3
#include <iostream>
#include <vector>
#include <deque>

using std::deque;
using std::vector;

class Solution
{
    // 自定义单调队列
public:
    class MyQueue
    {
    public:
        // deque是双端队列(容器)
        deque<int> que;
        // 三个成员函数pop/push/front
        void pop(int val)
        {
            // val = 5
            // 队列: 3 -1 -3
            // pop(nums[i-k])
            // pop(3)
            if (!que.empty() && val == que.front())
            {
                que.pop_front();
            }
        }
        void push(int val)
        {
            // val = 3
            // 队列: 1
            while (!que.empty() && val > que.back())
            {
                que.pop_back();
            }
            // val = 1
            // 队列: 空
            que.push_back(val);
        }
        int front()
        {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue que;
        vector<int> result;
        // 先处理前K个值
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};