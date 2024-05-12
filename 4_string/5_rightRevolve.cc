// n = 2
// s = abcdef
// 输出 efabcd
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
    // abcd=>dcba
    // ef=>fe
    // dcbafe=>efabcd
    int len = s.size();
    reverse(s.begin(), s.begin() + len - n);
    reverse(s.begin() + len - n, s.end());
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}