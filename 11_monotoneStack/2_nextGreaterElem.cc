#include <vector>
#include <stack>
#include <unordered_map>

using std::stack;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // 将nums1映射到umap中 k是nums[i] v是i
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++)
        {
            umap[nums1[i]] = i;
        }
        // 使用单调递增栈对nums2进行处理
        stack<int> st;
        // 保存结果容器
        vector<int> result(nums1.size(), -1);
        // 边界处理
        if (nums1.size() == 0)
        {
            return result;
        }
        // 先将下标0入栈
        st.push(0);
        // 从1开始
        for (int i = 1; i < nums2.size(); i++)
        {
            if (nums2[i] < nums2[st.top()])
            {
                st.push(i);
            }
            else if (nums2[i] == nums2[st.top()])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && nums2[i] > nums2[st.top()])
                {
                    // 若栈顶对应的元素在nums1中存在
                    if (umap.count(nums2[st.top()]))
                    {
                        // 获取栈顶对应的元素在nums1中的下标
                        int index = umap[nums2[st.top()]];
                        result[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};