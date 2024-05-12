// 移动匹配
#include <iostream>

using std::string;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // s = abcabc
        // t = abcabc abcabc
        // t =  bcabc abcab
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        // 注意std::string::npos
        if(t.find(s) != std::string::npos){
            return true;
        }
        return false;
    }
};