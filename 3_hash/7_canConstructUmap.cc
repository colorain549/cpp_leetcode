#include <iostream>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < magazine.size(); i++)
        {
            umap[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.size(); j++)
        {
            umap[ransomNote[j] - 'a']--;
        }
        auto it = umap.begin();
        for (; it != umap.end(); ++it)
        {
            if (it->second < 0)
            {
                return false;
            }
        }
        return true;
    }
};