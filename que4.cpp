#include <iostream>
#include <cctype>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
public:
    Node* topNode;
    
    Stack() {
        topNode = nullptr;
    }

    void push(char val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = topNode;
        topNode = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
        Node* temp = topNode;
        char popped = topNode->data;
        topNode = topNode->next;
        delete temp;
        return popped;
    }

    char top() {
        if (!isEmpty()) {
            return topNode->data;
        }
        return '\0';
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(const string& infix) {
    Stack stack;
    string postfix = "";
    
    for (char ch : infix) 
    {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                postfix += stack.pop();
            }
            stack.pop();  // Pop the '('
        }
        else if (isOperator(ch)) {
            while (!stack.isEmpty() && precedence(stack.top()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

int main() {
    string infix;
    
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
