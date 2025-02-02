#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix to postfix
string prefixToPostfix(string prefix)
{
    stack<string> st;

    // Read the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {
            // Pop two operands from stack
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            // Create a new postfix expression
            string temp = op1 + op2 + prefix[i];

            // Push the new expression back to stack
            st.push(temp);
        }
        else
        {
            // Operand, push to stack
            st.push(string(1, prefix[i]));
        }
    }

    // The final postfix expression
    return st.top();
}

int main()
{
    string prefix = "*+AB-CD";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    return 0;
}
