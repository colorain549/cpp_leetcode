#include <vector>
#include <stack>
#include <algorithm>

using std::min;
using std::stack;
using std::vector;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // 保存下标的栈
        stack<int> st;
        // 保存结果
        int sum = 0;
        // 边界处理
        if (height.size() <= 2)
        {
            return sum;
        }
        // 先将下标0入栈
        st.push(0);
        // 从1开始
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] < height[st.top()])
            {
                st.push(i);
            }
            // 注意这里是if-else而不是else if
            if (height[i] == height[st.top()])
            {
                // st.pop();
                st.push(i);
            }
            else
            {
                while (!st.empty() && height[i] > height[st.top()])
                {
                    // 中间列的下标
                    int mid = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        // height[st.top]为左侧最高的高度
                        // height[i]为右侧最高的高度
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};