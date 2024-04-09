// 输出
// fasle
#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

class Solution
{
public:
    bool isValid(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            // 将对应的右括号入栈
            if (s[i] == '(')
            {
                _st.push(')');
            }
            else if (s[i] == '[')
            {
                _st.push(']');
            }
            else if (s[i] == '{')
            {
                _st.push('}');
            }
            // 栈为空或栈顶元素不等于当前遍历的元素
            // 即多余的右括号
            else if (_st.empty() || _st.top() != s[i])
            {
                return false;
            }
            // 找到对应的右括号就出栈
            else
            {
                _st.pop();
            }
        }
        return _st.empty();
    }

private:
    stack<int> _st;
};

int main()
{
    bool result;

    string s = "()[]{}";

    Solution solution;
    result = solution.isValid(s);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}