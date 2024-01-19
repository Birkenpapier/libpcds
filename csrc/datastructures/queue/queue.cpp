#include <iostream>
#include <stdexcept>

// node structure
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
    Node* front;  
    Node* rear;   
    int size;     

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty");
        }

        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        int data = temp->data;
        delete temp;
        size--;
        return data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getFront() const {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element is: " << q.getFront() << std::endl;
    std::cout << "Removed " << q.dequeue() << " from queue" << std::endl;
    std::cout << "Front element is now: " << q.getFront() << std::endl;

    q.enqueue(40);
    std::cout << "Added 40 to queue" << std::endl;

    while (!q.isEmpty()) {
        std::cout << "Removed " << q.dequeue() << " from queue" << std::endl;
    }

    return 0;
}
