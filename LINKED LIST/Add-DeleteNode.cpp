#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;

    // Constructor to initialize a node//
    Node(int value) : data(value), next(nullptr) {}
};

// Linked List class
class LinkedList
{
private:
    Node *head;

public:
    // Constructor to initialize the linked list
    LinkedList() : head(nullptr) {}

    // Function to add a node at the end
    void addNode(int value)
    {
        Node *newNode = new Node(value);

        if (!head)
        { // If the list is empty
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Node added with value: " << value << endl;
    }

    // Function to delete a node by value
    void deleteNode(int value)
    {
        if (!head)
        { // If the list is empty
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        // If the node to be deleted is the head
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted with value: " << value << endl;
            return;
        }

        // Traverse to find the node to delete
        Node *temp = head;
        Node *prev = nullptr;

        while (temp && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if (!temp)
        { // Node not found
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        // Delete the node
        prev->next = temp->next;
        delete temp;
        cout << "Node deleted with value: " << value << endl;
    }

    // Function to display the list
    void display()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~LinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;

    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    list.display();

    list.deleteNode(20);
    list.display();

    list.deleteNode(40); // Try to delete a non-existent node
    list.display();

    return 0;
}
