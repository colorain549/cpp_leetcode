// n = 2
// s = abcdef
// 输出 cdefab
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::reverse;
using std::string;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    // ab=>ba
    // cdef=>fedc
    // bafedc=>cdefab
    int len = s.size();
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}