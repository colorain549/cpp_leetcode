// -1的前缀表
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 构建-1的前缀表(next数组)
void getNext(int *next, const string &s)
{
    // 初始化j为-1
    int j = -1;
    // 初始化next[0]为-1
    next[0] = j;
    // 从1开始
    // i表示前缀表的下标/字符数组s的下标
    // j为最长公共前后缀长度
    for (int i = 1; i < s.size(); i++)
    {
        // 不符合公共前后缀(如aab)
        while (j >= 0 && s[i] != s[j + 1])
        {
            // 回退
            j = next[j];
        }
        // 符合公共前后缀(如aa)
        if (s[i] == s[j + 1])
        {
            // 最长公共前后缀长度+1
            j++;
        }
        // 填充前缀表
        next[i] = j;
    }
}

// 测试代码
int main()
{
    string s = "aabaaf";
    int next[s.size()];
    getNext(next, s);
    for (int i = 0; i < s.size(); i++)
    {
        cout << next[i] << " ";
    }
    cout << endl;

    return 0;
}