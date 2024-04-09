// 输出
// 1
// 1
// false
#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        _stIn.push(x);
    }

    int pop()
    {
        // 将stackIn的元素全部移到stackOut
        while (!_stIn.empty())
        {
            int tmp = _stIn.top();
            _stOut.push(tmp);
            _stIn.pop();
        }
        // 返回并弹出stackOut的栈顶元素
        int tmp = _stOut.top();
        _stOut.pop();
        return tmp;
    }

    int peek()
    {
        // 将弹出stackOut的栈顶元素重新入栈
        int tmp = this->pop();
        _stOut.push(tmp);
        // 返回栈顶元素
        return _stOut.top();
    }

    bool empty()
    {
        return _stIn.empty() && _stOut.empty();
    }

private:
    stack<int> _stIn;
    stack<int> _stOut;
};

int main()
{
    int resultInt;
    bool resultBool;

    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    // 1
    resultInt = myQueue.peek();
    cout << resultInt << endl;
    // 1
    resultInt = myQueue.pop();
    cout << resultInt << endl;
    // false
    resultBool = myQueue.empty();
    if (resultBool)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}