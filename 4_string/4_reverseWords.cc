// 输出
//
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
public:
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

public:
    void removeExtraSpaces(string &s)
    {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            // 第一个单词前不留空格
            if (s[fast] != ' ')
            {
                // 单词之间留空
                if (slow != 0)
                {
                    s[slow] = ' ';
                    slow++;
                }
            }
            // 将连续的非空格字符复制到新字符串中
            while (fast < s.size() && s[fast] != ' ')
            {
                s[slow++] = s[fast++];
            }
        }
        // 记得调整大小
        s.resize(slow);
    }

    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            // size包含空格
            if (i == s.size() || s[i] == ' ')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

int main()
{
    return 0;
}