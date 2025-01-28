#include <iostream>
using namespace std;
class Queue {
private:
    int* arr;
    int front, rear, capacity, size;
public:
    Queue(int cap) {
        arr = new int[cap];
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
    }
    void enqueue(int x) {
        if (size == capacity) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }
    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int result = arr[front];
        front = (front + 1) % capacity;
        size--;
        return result;
    }
    int peek() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
      int backe() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty() {
        return size == 0;
    }
    ~Queue() {
        delete[] arr;
    }
};
int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "Front element is " << q.peek() << endl;
   // cout << "Dequeued element is " << q.dequeue() << endl;
    cout << "Queue is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout<<q.backe();
    return 0;
}
