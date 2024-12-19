#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class CircularQueue {
private:
    Node* front;  
    Node* rear;   
public:
      CircularQueue() {
        front = rear = nullptr;
    }
    bool isEmpty() {
        return (front == nullptr);
    }
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; 
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; 
        }
        cout << "Enqueued: " << value << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            rear->next = front;  
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }

    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display(); 

    q.dequeue();  
    q.dequeue(); 

    q.display(); 

    q.enqueue(50);
    q.enqueue(60);

    q.display();  

    return 0;
}
