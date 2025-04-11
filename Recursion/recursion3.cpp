#include <iostream>

// Function to calculate factorial using recursion
long long factorial(int n)
{
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    return n * factorial(n - 1);
}

int main()
{
    int num;

    // Taking input from the user
    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    // Validating input
    if (num < 0)
    {
        std::cout << "Factorial is not defined for negative numbers.\n";
    }
    else
    {
        // Calling the recursive function/.
        std::cout << "Factorial of " << num << " is " << factorial(num) << "\n";
    }

    return 0;
}
