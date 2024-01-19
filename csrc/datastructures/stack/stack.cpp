#include <iostream>
#include <stdexcept>

// node structure for Stack
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            throw std::out_of_range("Stack is empty");
        }

        Node* temp = top;
        top = top->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int peek() const {
        if (top == nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        return top->data;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is: " << stack.peek() << std::endl;
    std::cout << "Popped " << stack.pop() << " from stack" << std::endl;
    std::cout << "Top element is now: " << stack.peek() << std::endl;

    stack.push(40);
    std::cout << "Pushed 40 to stack" << std::endl;

    while (!stack.isEmpty()) {
        std::cout << "Popped " << stack.pop() << " from stack" << std::endl;
    }

    return 0;
}
