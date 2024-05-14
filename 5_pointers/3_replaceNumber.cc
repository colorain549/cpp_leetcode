#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // a1b => anumberb
    // 012 => 01234567
    string s;
    while (cin >> s)
    {
        // 原始字符串最大下标(2)
        int sOldIndex = s.size() - 1;
        // 计算数字的数量
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 注意
            if (s[i] >= '0' && s[i] <= '9')
            {
                count++;
            }
        }
        // 调整大小
        s.resize(s.size() + count * 5);
        // 新字符串最大下标(7)
        int sNewIndex = s.size() - 1;
        // 注意
        while (sOldIndex >= 0)
        {
            // 遇到数字就填充单词
            if (s[sOldIndex] >= '0' && s[sOldIndex] <= '9')
            {
                s[sNewIndex--] = 'r';
                s[sNewIndex--] = 'e';
                s[sNewIndex--] = 'b';
                s[sNewIndex--] = 'm';
                s[sNewIndex--] = 'u';
                s[sNewIndex--] = 'n';
            }
            else
            {
                // 遇到字母
                s[sNewIndex--] = s[sOldIndex];
            }
            // 注意
            sOldIndex--;
        }
        cout << s << endl;
    }

    return 0;
}