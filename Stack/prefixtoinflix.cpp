

            // Form an infix expression and push it back to stack
            string infix = "(" + op1 + c + op2 + ")";
            st.push(infix);
        }
    }

    // The final infix expression is on top of the stack//.././
    return st.top();
}

int main()
{
    string prefix = "*+AB-CD"; // Example: Prefix Expression././././

    string infix = prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
