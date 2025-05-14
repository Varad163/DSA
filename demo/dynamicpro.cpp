#include <iostream>
#include <unordered_map>
using namespace std;

int fib(int n, unordered_map<int, int> &memo)
{
    if (memo.count(n))
        return memo[n];
    if (n <= 1)
        return n;
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main()
{
    unordered_map<int, int> memo;
    cout << fib(10, memo) << endl; // Output: 55
    return 0;
}
