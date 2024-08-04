// 输出
// o l l e h 
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;

#include <vector>

class Solution {
public:
    // Custom swap function
    void exchange(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }

    void reverseString(std::vector<char>& s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            exchange(s[i], s[j]);
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