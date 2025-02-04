#include <iostream>
#include <stack>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert Postfix to Prefix
string postfixToPrefix(string postfix)
{
    stack<string> st;

    // Traverse postfix expression
    for (char c : postfix)
    {
        if (isOperator(c))
        {
            // Pop two operands
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            // Form new expression
            string temp = c + op1 + op2;

            // Push result back to stack
            st.push(temp);
        }
        else
        {
            // If operand, push onto stack
            st.push(string(1, c));
        }
    }

    // Final result is on the top of the stack
    return st.top();
}

// Driver code
int main()
{
    string postfix = "ABC*+D-";
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
    return 0;
}
