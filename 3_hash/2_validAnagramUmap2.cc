#include <iostream>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<int, int> umap;
        // 建立映射 k是s[i] v该是该字母出现的频率
        for (int i = 0; i < s.size(); i++)
        {
            umap[s[i]]++;
        }
        // 建立映射 k是t[i] v该是该字母出现的频率
        for (int i = 0; i < t.size(); i++)
        {
            umap[t[i]]--;
        }
        // 检查umap中的v是否全为0
        for (auto it = umap.begin(); it != umap.end(); ++it)
        {
            if (it->second != 0)
            {
                return false;
            }
        }
        // for (const auto &elem : umap)
        // {
        //     if (elem.second != 0)
        //     {
        //         return false;
        //     }
        // }
        return true;
    }
};