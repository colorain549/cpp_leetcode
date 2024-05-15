#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

int main()
{
    vector<int> nums{2, 6, 2, 1, 3};

    // 声明优先级队列
    // 元素的类型, 存储优先级队列中元素的容器, 
    // 排序方法(默认greater小顶堆, 从大到小)
    priority_queue<int, vector<int>> pque;
    // 往优先级队列添加元素
    for (int i = 0; i != nums.size(); i++)
    {
        pque.push(nums[i]);
    }
    // 输出优先级队列元素
    while (!pque.empty())
    {
        cout << pque.top() << " ";
        pque.pop();
    }
    cout << endl;

    return 0;
}