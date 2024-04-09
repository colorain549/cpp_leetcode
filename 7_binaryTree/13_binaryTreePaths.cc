// 输出
// 1->2->5 1->3 
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printVec(vector<string> &ivec)
{
    for (auto &elem : ivec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

class Solution
{
private:
    void traversal(TreeNode *node, vector<int> &path, vector<string> &result)
    {
        path.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
        }

        if (node->left)
        {
            traversal(node->left, path, result);
            // 记得回溯
            path.pop_back();
        }

        if (node->right)
        {
            traversal(node->right, path, result);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> result;

        traversal(root, path, result);
        return result;
    }
};

int main()
{
    vector<string> result;

    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(3);
    TreeNode *fourth = new TreeNode(5);

    root->left = sec;
    root->right = third;
    sec->right = fourth;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.binaryTreePaths(root);

    printVec(result);

    // 释放内存
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}