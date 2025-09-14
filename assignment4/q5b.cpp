#include <iostream>
#include <queue>
using namespace std;

class StackWithOneQueue
{
private:
    queue<int> q;

public:
    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        q.pop();
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

void runOneQueueExample()
{
    StackWithOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.top() << endl; // Output: 30
    s.pop();
    cout << "Top element after pop is: " << s.top() << endl; // Output: 20
}

int main()
{
    runOneQueueExample();
    return 0;
}
