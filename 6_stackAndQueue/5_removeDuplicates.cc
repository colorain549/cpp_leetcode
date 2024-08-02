// 输出
// ca
#include <iostream>
#include <vector>
#include <stack>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::reverse;
using std::stack;
using std::string;
using std::vector;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        // abbaca
        // 空栈
        stack<int> st;
        // 操作
        for (int i = 0; i < s.size(); i++)
        {
            // 栈为空
            // 栈顶元素不等于当前遍历的元素
            if (st.empty() || st.top() != s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        // 保存结果的容器
        string result;
        // 处理栈内剩下的字符ac
        while (!st.empty())
        {
            // 保存中间结果
            result.push_back(st.top());
            st.pop();
        }
        // 将字符串逆序成ca
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    string result;

    string s("abbaca");

    Solution solution;
    result = solution.removeDuplicates(s);

    cout << result << endl;

    return 0;
}