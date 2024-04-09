#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution
{
public:
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