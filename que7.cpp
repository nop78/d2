#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;


struct Node {
    char data;      
    Node* left;      
    Node* right;    

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);           
    cout << root->data << " ";        
    inorder(root->right);           
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";       
    preorder(root->left);            
    preorder(root->right);            
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);            
    postorder(root->right);           
    cout << root->data << " ";       
}


bool isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

Node* constructFromPostfix(const string& postfix) {
    stack<Node*> st;

    for (char ch : postfix) {
        if (isOperand(ch)) {
            st.push(new Node(ch));
        } else {
            Node* right = st.top();
            st.pop();
            Node* left = st.top();
            st.pop();

            Node* opNode = new Node(ch);
            opNode->left = left;
            opNode->right = right;

            st.push(opNode);
        }
    }

    return st.top(); 
}

Node* constructFromPrefix(const string& prefix) {
    stack<Node*> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isOperand(ch)) {
            st.push(new Node(ch));
        } else {
            Node* left = st.top();
            st.pop();
            Node* right = st.top();
            st.pop();

            Node* opNode = new Node(ch);
            opNode->left = left;
            opNode->right = right;

            st.push(opNode);
        }
    }

    return st.top();  
}

int main() {
    string postfix = "ab+c*";  
    string prefix = "*+abc";   

    
    Node* rootPostfix = constructFromPostfix(postfix);
    cout << "Postfix Expression Tree Traversals:" << endl;
    cout << "In-order: ";
    inorder(rootPostfix);
    cout << "\nPre-order: ";
    preorder(rootPostfix);
    cout << "\nPost-order: ";
    postorder(rootPostfix);
    cout << endl;

    Node* rootPrefix = constructFromPrefix(prefix);
    cout << "\nPrefix Expression Tree Traversals:" << endl;
    cout << "In-order: ";
    inorder(rootPrefix);
    cout << "\nPre-order: ";
    preorder(rootPrefix);
    cout << "\nPost-order: ";
    postorder(rootPrefix);
    cout << endl;

    return 0;
}
