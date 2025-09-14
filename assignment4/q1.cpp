#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int capacity;
    int* arr;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
        rear = capacity - 1;  
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << ".\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
        cout << item << " enqueued to queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek.\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);

    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Is Empty?\n4. Is Full?\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1)
                    cout << "Dequeued: " << value << "\n";
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 5:
                q.display();
                break;
            case 6:
                value = q.peek();
                if (value != -1)
                    cout << "Front element: " << value << "\n";
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 7);

    return 0;
}
