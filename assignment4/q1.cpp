#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class SimpleQueue
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    SimpleQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << "\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        int dequeuedValue = arr[front];
        cout << "Dequeued: " << dequeuedValue << "\n";
        if (front == rear)
        {
            // Last element is dequeued, reset queue
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No element to peek.\n";
            return;
        }
        cout << "Element at the front is: " << arr[front] << "\n";
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

void showMenu()
{
    cout << "\n--- Simple Queue Menu ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Check if Empty\n";
    cout << "6. Check if Full\n";
    cout << "7. Exit\n";
    cout << "-------------------------\n";
    cout << "Enter your choice: ";
}

int main()
{
    SimpleQueue queue;
    int choice = 0;
    int value;

    while (choice != 7)
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.peek();
            break;
        case 4:
            queue.display();
            break;
        case 5:
            if (queue.isEmpty())
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Queue is not empty.\n";
            }
            break;
        case 6:
            if (queue.isFull())
            {
                cout << "Queue is full.\n";
            }
            else
            {
                cout << "Queue is not full.\n";
            }
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
