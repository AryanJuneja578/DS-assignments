#include <iostream>
using namespace std;

class Stack {
    int arr[10];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(int num) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << num << "\n";
            return;
        }
        arr[++top] = num;
        cout << num << " pushed into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 9;
    }

    void display()
    {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "<===== Stack Elements =====>\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << "\n";
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek.\n";
            return;
        }
        cout << "Top element: " << arr[top] << "\n";
    }
};
int main() {
    
    Stack stackk;
    int option, num;
    bool running = true;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1 - Push\n";
        cout << "2 - Pop\n";
        cout << "3 - Peek\n";
        cout << "4 - Display\n";
        cout << "5 - Check if Empty\n";
        cout << "6 - Check if Full\n";
        cout << "7 - Exit\n";
        cout << "Enter choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter number to push: ";
                cin >> num;
                stackk.push(num);
                stackk.display();
                break;

            case 2:
                stackk.pop();
                break;

            case 3:
                stackk.peek();
                break;

            case 4:
                stackk.display();
                break;

            case 5:
                cout << (stackk.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;

            case 6:
                cout << (stackk.isFull() ? "Stack is full.\n" : "Stack is not full.\n");
                break;

            case 7:
                running = false;
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
