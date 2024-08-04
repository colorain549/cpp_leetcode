#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> record(26, 0);
        // 建立映射index是s[i] v是该字母的频率
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }
        // 建立映射index是t[i] v是该字母的频率
        for (int i = 0; i < t.size(); i++)
        {
            record[t[i] - 'a']--;
        }
        // 检查record数组中的频率是否全为0
        for (int i = 0; i < 26; i++)
        {
            if (record[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};