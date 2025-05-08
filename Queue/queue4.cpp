#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::queue<std::string> customerQueue;

    // Customers arriving
    customerQueue.push("Alice");
    customerQueue.push("Bob");
    customerQueue.push("Charlie");

    std::cout << "Serving customers in order:\n";

    // Process the queue
    while (!customerQueue.empty())
    {
        std::cout << "Serving: " << customerQueue.front() << std::endl;
        customerQueue.pop();
    }

    std::cout << "All customers have been served.\n";

    return 0;
}
