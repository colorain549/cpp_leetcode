#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution
{
public:
    // 构建-1的前缀表(next数组)
    void getNext(int *next, const string &s)
    {
        int j = -1;
        next[0] = j;
        // 从1开始
        for (int i = 1; i < s.size(); i++)
        {
            if (j >= 0 && s[i] != s[j + 1])
            {
                // 回退
                j = next[j];
            }
            if (s[i] == s[j + 1])
            {
                j++;
            }
            // 填充数组
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        int j = -1;
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1])
            {
                j++;
            }
            if (j == needle.size() - 1)
            {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};

int main()
{
    // string s = "aabaaf";
    // // int next[s.size()];
    // vector<int> next(s.size());
    // Solution solution;
    // // solution.getNext(next, s);
    // solution.getNext(&next[0], s);
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << next[i] << " ";
    // }
    // cout << endl;

    string s1 = "aabaabaaf";
    string s2 = "aabaaf";
    Solution solution;
    int ret = solution.strStr(s1, s2);
    cout << ret << endl;

    return 0;
}