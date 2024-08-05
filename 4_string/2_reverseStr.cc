// 输出
// bacdfeg
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::vector;

class Solution
{
private:
    void reverse(string &s, int begin, int end)
    {
        for (int i = begin, j = end; i < j; i++, j--)
        {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }

public:
    string reverseStr(string s, int k)
    {
        // abcd ef g
        // ba   fe 
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            // 长度大于k小于2k则反转前k
            if (i + k <= s.size())
            {
                reverse(s, i, i + k - 1);
            }
            // 长度小于k则全部反转
            else
            {
                reverse(s, i, s.size() - 1);
            }
        }
        return s;
    }
};

int main()
{
    string result;

    string s = "abcdefg";
    int k = 2;

    Solution solution;
    result = solution.reverseStr(s, k);

    cout << result << endl;

    return 0;
}