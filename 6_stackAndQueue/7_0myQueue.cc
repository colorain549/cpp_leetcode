// nums = [1,3,-1,-3,5,3,6,7], k = 3
#include <iostream>
#include <vector>
#include <deque>

using std::deque;
using std::vector;

class Solution
{
    // 维护单调队列
public:
    class MyQueue
    {
    public:
        // deque是双端队列
        deque<int> que;
        // 三个成员函数pop/push/front
        void pop(int val)
        {
            // val = 5
            // 队列: 3 -1 -3
            // pop(nums[i-k])
            // pop(nums[4-3])
            // pop(nums[1])
            // pop(3)
            if(!que.empty() && val == que.front()){
                que.pop_front();
            }
        }
        void push(int val)
        {
            // val = 3
            // 队列: 1
            // 空
            while (!que.empty() && val > que.back())
            {
                que.pop_back();
            }
            // val = 1
            // 队列: 空
            // 1
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
    }
};