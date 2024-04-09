#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution solution;
    solution.reverseString(s);

    for (auto &elem : s)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}