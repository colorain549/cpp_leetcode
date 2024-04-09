// 输出
// 2
// 2
// false
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        _que.push(x);
    }

    int pop()
    {
        // 将队列前n-1个元素重新加入队列(画图)
        int size = _que.size() - 1;
        for (int i = 0; i < size; i++)
        {
            int tmp = _que.front();
            _que.push(tmp);
            _que.pop();
        }
        int tmp = _que.front();
        _que.pop();
        return tmp;
    }

    int top()
    {
        // 取队尾(画图)
        return _que.back();
    }

    bool empty()
    {
        return _que.empty();
    }

private:
    queue<int> _que;
};

int main()
{
    int resultInt;
    int resultBool;

    MyStack myStack;
    myStack.push(1);
    myStack.push(2);

    // 输出2
    resultInt = myStack.top();
    cout << resultInt << endl;

    // 输出2
    resultInt = myStack.pop();
    cout << resultInt << endl;

    // 输出false
    resultBool = myStack.empty();
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