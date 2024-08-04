## 哈希表

2. 有效的字母异位词(242)(使用数组)  
2 有效的字母异位词(242)(使用umap)
2 有效的字母异位词(242)(使用vector)
3. 两个数组的交集(349)(使用for...auto)
3 两个数组的交集(349)(使用迭代器unordered_set<int>::iterator it)
```
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
```
4. 快乐数(202)  
5 两数之和(1)(双层for循环)
5. 两数之和(1)(umap)
6. 四数之和2(454)
7. 赎金信(383)
8. 三数之和(15)
9. 四数之和(18)