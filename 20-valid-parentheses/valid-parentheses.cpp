#include <stack>
#include <string>
using namespace std;

class Solution {
    stack<char> st;
public:
    bool isValid(string s) {
        for(char c : s){
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                if( (c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[') ) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};