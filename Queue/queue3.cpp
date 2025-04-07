#include <iostream>
#include <queue>
#include <string>

int main()
{
  
    std::queue<std::string> animals;

    animals.push("Cat");
    animals.push("Dog");
    animals.push("Fox");


   
    std::cout << "Queue: ";
    while (!animals.empty())
    {
       
        std::cout << animals.front() << " ";
   
        animals.pop();
    }
    std::cout << std::endl;

    return 0;
}
