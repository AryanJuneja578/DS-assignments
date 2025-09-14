#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.empty()) return;

    int halfSize = q.size() / 2;
    stack<int> s;

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, x;

    cout << "Enter number of elements (even number): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Number of elements should be even.\n";
        return 1;
    }

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}
