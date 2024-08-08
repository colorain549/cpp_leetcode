## 哈希表

2. 有效的字母异位词(242)(使用数组)  
2 有效的字母异位词(242)(使用umap+for...auto)  
2 有效的字母异位词2(242)(使用umap+迭代器)  
2 有效的字母异位词(242)(使用vector)  
3. 两个数组的交集(349)(先处理1个数组+for...auto)  
3 两个数组的交集(349)(先处理2个数组+迭代器)
4. 快乐数(202)
5 两数之和(1)(双层for循环)
5. 两数之和(1)(umap)
6. 四数之和2(454)
7. 赎金信(383)(使用数组)  
7 赎金信(383)(使用umap+迭代器)  
7 赎金信(383)(使用umap+for...auto)  
7 赎金信(383)(使用vector)  
8. 三数之和(15)
```
for(int i=0; i<nums.size(); i++){
    if(i>0 && nums[i]==nums[i-1]){
        continue;
    }
    int left = i + 1;
    int right = nums.size() - 1;
    while(left<right){
        if(nums[i]+nums[left]+nums[right]>0){
            right--;
        }
        else if(nums[i]+nums[left]+nums[right]<0){
            left++;
        }
        else
        {
            result.push_back(nums[i],nums[left],nums[right]);
            while(left<right && nums[left]==nums[left+1]){
                left++;
            }
            while(left<right && nums[right]==nums[right-1]){
                right--;
            }
            left++;
            right--;
        }
    }
}
```
9. 四数之和(18)

补充(umap的使用):
1. for...auto
```
for(const auto &it: umap){
    if(it.second < 0){
        return false;
    }
}
```
2. 迭代器
```
for(auto it = umap.begin(); it != umap.end(); ++it){
    if(it->second < 0){
        return false;
    }
}
```