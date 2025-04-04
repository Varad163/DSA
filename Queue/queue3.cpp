#include <iostream>
#include <queue>
#include <string>

int main()
{
  
    std::queue<std::string> animals;

    // Enqueue (push) some elements
    animals.push("Cat");
    animals.push("Dog");
    animals.push("Fox");


   
    std::cout << "Queue: ";
    while (!animals.empty())
    {
       
        std::cout << animals.front() << " ";
        // Remove the front element from the queue
        animals.pop();
    }
    std::cout << std::endl;

    return 0;
}
