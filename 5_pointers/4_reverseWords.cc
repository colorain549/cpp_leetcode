#include <iostream>
#include <algorithm>

using std::string;
using std::swap;

class Solution
{
private:
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

public:
    void removeExtraSpaces(string s)
    {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            // 第一个单词前的空格
            if (s[fast] != ' ')
            {
                // 单词之间的空格
                if (slow != 0)
                {
                    slow = ' ';
                    slow++;
                }
            }
            // 复制字符串(注意fast != ' ')
            while (fast < s.size() && s[fast] != ' ')
            {
                s[slow] = s[fast];
                fast++;
                slow++;
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s)
    {
        // 去除空格
        removeExtraSpaces(s);
        // 反转整个字符串
        reverse(s, 0, s.size() - 1);
        // 注意start的位置
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size() && s[i] == ' ')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};