## 数组

2.二分查找(704)  
2-1 左闭右闭区间
```
int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    // [left, right]
    // [1, 1]合法
    while (low <= high)
    {
        ...
    }
    return -1;
}
```
  
2-2 左闭右开区间(难点)  
3. 移除元素(27)
```
// 当快指针没有指向要找的值
{
if (nums[fast] != val)
    // 数组中删除的实质是覆盖
    nums[slow] = nums[fast];
    // 快慢指针同时移动
    slow++;
}
```
4. 有序数组的平方(977)
5. 长度最小的子数组(209)
```
for (int j = 0; j < nums.size(); j++)
{
    sum += nums[j];
    while (sum >= target)
    {
        subLength = j - i + 1;
        result = min(result, subLength);
        // 下面2个语句顺序不能调换(!!!注意!!!)
        sum -= nums[i];
        i++;
    }
}
// 若result存在则返回result
// 否则返回0
return result == INT32_MAX ? 0 : result;
```