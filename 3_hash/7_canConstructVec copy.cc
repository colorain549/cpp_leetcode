#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> record(26, 0);
        // 统计magazine中各字符出现的频率
        for (int i = 0; i < magazine.size(); i++)
        {
            record[magazine[i] - 'a']++;
        }
        // 减去ransomNote中各字符出现的频率
        for (int j = 0; j < ransomNote.size(); j++)
        {
            record[ransomNote[j] - 'a']--;
            // 若出现负的频率则返回false
            if (record[ransomNote[j] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};