#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;
    
public:
    Stack() {
        topNode = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack underflow");
        }
        Node* temp = topNode;
        int value = topNode->data;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    int top() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int evaluatePostfix(const string& expression) {
    Stack stack;

    for (char ch : expression) {
        if (isdigit(ch)) 
        {
            stack.push(ch - '0');
        }
        else if (ch == ' ') {
            continue;  
        }
        else 
        {
            int val2 = stack.pop();
            int val1 = stack.pop();
            
            switch (ch) {
                case '+':
                    stack.push(val1 + val2);
                    break;
                case '-':
                    stack.push(val1 - val2);
                    break;
                case '*':
                    stack.push(val1 * val2);
                    break;
                case '/':
                    stack.push(val1 / val2);
                    break;
                case '^':
                    stack.push(pow(val1, val2)); 
                    break;
                default:
                    throw runtime_error("Invalid operator");
            }
        }
    }

    return stack.pop();
}

int main() {
    string postfixExpression;
    
    cout << "Enter a postfix expression: ";
    getline(cin, postfixExpression);

    try {
        int result = evaluatePostfix(postfixExpression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
