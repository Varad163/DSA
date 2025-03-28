#include <iostream>
#include <string>

using namespace std;

// Node structure for Doubly Linked List
struct Node
{
    string text;
    Node *prev;
    Node *next;

    Node(string t) : text(t), prev(nullptr), next(nullptr) {}
};

// UndoRedo class using a Doubly Linked List
class UndoRedo
{
private:
    Node *current; // Pointer to current state

public:
    UndoRedo()
    {
        current = new Node(""); // Initial empty state
    }

    // Add a new state (new edit)
    void edit(const string &newText)
    {
        Node *newNode = new Node(newText);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    // Undo operation (move back)
    void undo()
    {
        if (current->prev)
        {
            current = current->prev;
            cout << "Undo: " << current->text << endl;
        }
        else
        {
            cout << "No more undos!" << endl;
        }
    }

    // Redo operation (move forward)
    void redo()
    {
        if (current->next)
        {
            current = current->next;
            cout << "Redo: " << current->text << endl;
        }
        else
        {
            cout << "No more redos!" << endl;
        }
    }

    // Show current text
    void show()
    {
        cout << "Current Text: " << current->text << endl;
    }
};

int main()
{
    UndoRedo editor;

    editor.edit("Hello");
    editor.edit("Hello, World!");
    editor.edit("Hello, World! Welcome");



    editor.show(); 

    editor.undo(); 
    editor.undo(); // Undo: "Hello"
    editor.undo(); // No more undos!

    editor.redo(); // Redo: "Hello, World!"
    editor.redo(); // Redo: "Hello, World! Welcome"
    editor.redo(); // No more redos!

    return 0;
}
