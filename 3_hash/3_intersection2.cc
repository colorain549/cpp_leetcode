#include <iostream>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // [1,2,2,1] => [1,2]
        unordered_set<int> uset(nums1.begin(), nums1.end());
        unordered_set<int> uset2(nums2.begin(), nums2.end());
        vector<int> result;
        unordered_set<int>::iterator it;
        for (it = uset2.begin(); it != uset2.end(); ++it)
        {
            if (uset.find(*it) != uset.end())
            {
                result.push_back(*it);
            }
        }
        return result;
    }
};