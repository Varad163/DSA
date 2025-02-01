#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *queue;
    int front, rear, size, capacity;

public:
    // Constructor
    CircularQueue(int cap)
    {
        capacity = cap;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~CircularQueue()
    {
        delete[] queue;
    }

    // Check if the queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Insert an element into the queue
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = value;
        size++;
        cout << value << " enqueued to queue\n";
    }

    // Remove an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << queue[front] << " dequeued from queue\n";
        if (front == rear)
        { // If only one element was present
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Get the front element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return queue[front];
    }

    // Display all elements in the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        for (int count = 0; count < size; count++)
        {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

// Main function to test CircularQueue
int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Queue is full

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
