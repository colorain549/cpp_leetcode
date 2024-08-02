## 栈与队列

2. 用栈实现队列(232)
3. 用队列实现栈(225)
4. 有效的括号(20)
5. 删除字符串中的所有相邻重复项(1047)
```
string removeDuplicates(string s)
    {
        // 字符串充当队列
        string result;
        for (int i = 0; i < s.size(); i++)
        {
            // 队列空或队尾元素不等于当前元素则入队
            if (result.empty() || s[i] != result.back())
            {
                result.push_back(s[i]);
            }
            else
            {
                // 队尾元素等于当前元素
                result.pop_back();
            }
        }
        return result;
    }
```
6. 逆波兰表达式(150)(long long)  
7_0myQueue单调队列
7. 滑动窗口最大值(自定义单调队列)
```
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
```
8_priorityQue优先级队列使用
8. 前K个高频元素(使用priority_queue和自定义函数对象)
```
class MyCompare
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            // 小顶堆
            return lhs.second > rhs.second;
        }
    };



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
```

