// 输出
// 9
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // long long型的stack
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            // 遇到符号则运算后入栈
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+")
                {
                    st.push(num2 + num1);
                }
                else if (tokens[i] == "-")
                {
                    st.push(num2 - num1);
                }
                else if (tokens[i] == "*")
                {
                    st.push(num2 * num1);
                }
                else if (tokens[i] == "/")
                {
                    st.push(num2 / num1);
                }
            }
            // 遇到数字就入栈
            else
            {
                // stoll 转换为long long型
                st.push(stoll(tokens[i]));
            }
        }
        // 返回栈顶元素
        int ret = st.top();
        return ret;
    }
};

int main()
{
    int result;

    vector<string> tokens = {"2", "1", "+", "3", "*"};

    Solution solution;
    result = solution.evalRPN(tokens);

    cout << result << endl;

    return 0;
}