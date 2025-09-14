#include <bits/stdc++.h>
using namespace std;
class StackWithTwoQueues
{
private:
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty. No top element." << endl;
            return -1; 
        }
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

void runTwoQueueExample()
{
    StackWithTwoQueues s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element is: " << s.top() << endl; // Output: 3
    s.pop();
    cout << "Top element after pop is: " << s.top() << endl; // Output: 2
}

int main()
{
    runTwoQueueExample();
    return 0;
}
