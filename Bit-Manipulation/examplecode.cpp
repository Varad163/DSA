#include <iostream>
using namespace std;

int main()
{
    int A = 5, B = 3;

    cout << "A & B: " << (A & B) << endl;   // AND/././../
    cout << "A | B: " << (A | B) << endl;   // OR
    cout << "A ^ B: " << (A ^ B) << endl;   // XOR
    cout << "~A: " << (~A) << endl;         // NOT
    cout << "A << 1: " << (A << 1) << endl; // Left Shift
    cout << "A >> 1: " << (A >> 1) << endl; // Right Shift

    return 0;
}
