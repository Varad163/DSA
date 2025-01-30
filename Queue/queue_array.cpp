#include <iostream>
#define SIZE 5 // Define the maximum size of the queue

class Queue
{
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return rear == SIZE - 1;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "Queue is full!\n";
            return;
        }
        if (front == -1)
            front = 0;
        items[++rear] = value;
        std::cout << value << " enqueued\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << items[front] << " dequeued\n";
        front++;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            std::cout << items[i] << " ";
        std::cout << std::endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
