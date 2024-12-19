#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    bool search(int value) {
        return searchRec(root, value);
    }

    int depth() {
        return depthRec(root);
    }

    void displayLeafNodes() {
        displayLeafNodesRec(root);
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }
    bool searchRec(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }
    int depthRec(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = depthRec(node->left);
        int rightDepth = depthRec(node->right);

        return max(leftDepth, rightDepth) + 1;
    }
    void displayLeafNodesRec(Node* node) {
        if (node == nullptr) {
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data << " ";
        }

        displayLeafNodesRec(node->left);
        displayLeafNodesRec(node->right);
    }
};
int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Depth of the tree: " << bst.depth() << endl;

    int value = 40;
    if (bst.search(value)) {
        cout << value << " is found in the tree." << endl;
    } else {
        cout << value << " is not found in the tree." << endl;
    }

    cout << "Leaf nodes: ";
    bst.displayLeafNodes();
    cout << endl;

    return 0;
}
