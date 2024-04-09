// 输出
// 0 1 9 16 100
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printVec(vector<int> &ivec)
{
    for (auto &elem : ivec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // 保存结果的数组
        vector<int> result(nums.size());
        // 保存结果的数组的下标
        int k = nums.size() - 1;
        // 注意for的形式
        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                result[k] = nums[i] * nums[i];
                k--;
                i++;
            }
            else
            {
                result[k] = nums[j] * nums[j];
                k--;
                j--;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> result;

    vector<int> nums{-4, -1, 0, 3, 10};

    Solution solution;
    result = solution.sortedSquares(nums);

    printVec(result);

    return 0;
}