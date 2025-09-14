#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            // Operand: directly add to output
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            // Pop until '('
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        } else if (isOperator(ch)) {
            // Pop operators with higher or equal precedence
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    string infix = "A+B*C/D+(E-F)";
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
