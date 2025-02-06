#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a given character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix to infix
string prefixToInfix(string prefix)
{
    stack<string> st;

    // Read the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        // If character is an operand, push it to stack
        if (isalnum(c))
        {
            string operand(1, c);
            st.push(operand);
        }
        // If character is an operator
        else if (isOperator(c))
        {
            // Pop two operands from stack
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            // Form an infix expression and push it back to stack
            string infix = "(" + op1 + c + op2 + ")";
            st.push(infix);
        }
    }

    // The final infix expression is on top of the stack
    return st.top();
}

int main()
{
    string prefix = "*+AB-CD"; // Example: Prefix Expression

    string infix = prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
