#include <iostream>
using namespace std;

int factorial(int n)
{
    // Base case
    if (n == 0 || n == 1)
        return 1;
    // Recursive case
    return n * factorial(n - 1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
