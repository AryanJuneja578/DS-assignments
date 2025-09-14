#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int count;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return (count == size);
    }

    bool isEmpty() {
        return (count == 0);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        count++;
        cout << "Enqueued: " << value << "\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        int dequeuedValue = arr[front];
        cout << "Dequeued: " << dequeuedValue << "\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        count--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No element to peek.\n";
            return;
        }
        cout << "Element at the front is: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements are: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << "\n";
    }
};

void showMenu() {
    cout << "\n--- Circular Queue Menu ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Check if Empty\n";
    cout << "6. Check if Full\n";
    cout << "7. Exit\n";
    cout << "---------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue cq(size);
    int choice = 0;
    int value;

    while (choice != 7) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cq.display();
                break;
            case 5:
                if (cq.isEmpty()) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Queue is not empty.\n";
                }
                break;
            case 6:
                if (cq.isFull()) {
                    cout << "Queue is full.\n";
                } else {
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
