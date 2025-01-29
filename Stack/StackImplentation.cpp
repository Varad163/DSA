#include <iostream>
#define MAX 100 // Maximum size of the stack
using namespace std;

class Stack
{
    int top;      // Index of the top element
    int arr[MAX]; // Array to store stack elements

public:
    Stack() : top(-1) {} 


    void push(int x)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into the stack\n";
    }

    // Pop an element from the stack
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from the stack\n";
    }

    // Peek the top element of the stack
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top < 0;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
