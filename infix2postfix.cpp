#include <iostream>
#include <stack>
#include <cctype>
using namespace std;


int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0; 
}


 string infixToPostfix(const  string& infix) {
     stack<char> s;
     string postfix;

    for (char ch : infix) {
        if ( isalnum(ch)) {
            postfix += ch; 
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); 
        } else { 
            while (!s.empty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

   
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
     string infixExpression;

    
     cout << "Enter an infix expression: ";
     getline( cin, infixExpression);

    
     string postfixExpression = infixToPostfix(infixExpression);

   
     cout << "Infix Expression: " << infixExpression <<  endl;
     cout << "Postfix Expression: " << postfixExpression <<  endl;

    return 0;
}
