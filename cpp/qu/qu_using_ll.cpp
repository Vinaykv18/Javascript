#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x)
    {
        Node *newNode = new Node(x);
        if (!rear)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue()
    {
        if (!front)
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        int result = front->data;
        Node *temp = front;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
        return result;
    }

    int peek()
    {
        if (!front)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    ~Queue()
    {
        while (front)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is " << q.peek() << endl;
    cout << "Dequeued element is " << q.dequeue() << endl;
    cout << "Queue is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    


    return 0;
}
