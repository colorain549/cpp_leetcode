#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // 保存下标的栈
        stack<int> st;
        // 保存结果容器; 记得初始化为0
        vector<int> result(temperatures.size(), 0);
        // 边界处理
        if (temperatures.size() == 0)
        {
            return result;
        }
        // 先将下标0入栈
        st.push(0);
        // 从1开始
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (temperatures[i] < temperatures[st.top()])
            {
                st.push(i);
            }
            else if (temperatures[i] == temperatures[st.top()])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};