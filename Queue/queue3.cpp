#include <iostream>
#include <queue>
#include <string>

int main()
{
    // Create a queue to hold string values
    std::queue<std::string> animals;

    // Enqueue (push) some elements
    animals.push("Cat");
    animals.push("Dog");
    animals.push("Fox");

    // Print and dequeue each element until the queue is empty
    std::cout << "Queue: ";
    while (!animals.empty())
    {
        // Access the front element of the queue
        std::cout << animals.front() << " ";
        // Remove the front element from the queue
        animals.pop();
    }
    std::cout << std::endl;

    return 0;
}
