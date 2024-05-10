#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // 保存下标的栈
        stack<int> st;
        // 保存结果容器
        vector<int> result(nums.size(), -1);
        // 边界处理
        if (nums.size() == 0)
        {
            return result;
        }
        // 先将下标0入栈
        st.push(0);
        // 从1开始 记得*2(模拟循环数组)
        for (int i = 0; i < nums.size() * 2; i++)
        {
            if (nums[i % nums.size()] < nums[st.top()])
            {
                st.push(i % nums.size());
            }
            else if (nums[i % nums.size()] == nums[st.top()])
            {
                st.push(i % nums.size());
            }
            else
            {
                while (!st.empty() && nums[i % nums.size()] > nums[st.top()])
                {
                    result[st.top()] = nums[i % nums.size()];
                    st.pop();
                }
                st.push(i % nums.size());
            }
        }
        return result;
    }
};