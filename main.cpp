#include <iostream>
using namespace std;

const int CAPACITY = 100;

// Stack using an array
class ArrayStack {
private:
    int items[CAPACITY];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool push(int value) {
        if (top == CAPACITY - 1) {
            return false;
        }

        top++;
        items[top] = value;
        return true;
    }

    bool pop(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        removedValue = items[top];
        top--;
        return true;
    }
};

// Stack using a linked list
class LinkedStack {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* top;

public:
    LinkedStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool push(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = top;
        top = newNode;
        return true;
    }

    bool pop(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        Node* temporary = top;
        removedValue = top->value;
        top = top->next;
        delete temporary;
        return true;
    }

    ~LinkedStack() {
        int removedValue;
        while (pop(removedValue)) {
        }
    }
};

// Queue using an array
class ArrayQueue {
private:
    int items[CAPACITY];
    int front;
    int numberOfItems;

public:
    ArrayQueue() {
        front = 0;
        numberOfItems = 0;
    }

    bool isEmpty() {
        return numberOfItems == 0;
    }

    bool enqueue(int value) {
        if (numberOfItems == CAPACITY) {
            return false;
        }

        int position = (front + numberOfItems) % CAPACITY;
        items[position] = value;
        numberOfItems++;
        return true;
    }

    bool dequeue(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        removedValue = items[front];
        front = (front + 1) % CAPACITY;
        numberOfItems--;
        return true;
    }
};

// Queue using a linked list
class LinkedQueue {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    bool enqueue(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        return true;
    }

    bool dequeue(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        Node* temporary = front;
        removedValue = front->value;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temporary;
        return true;
    }

    ~LinkedQueue() {
        int removedValue;
        while (dequeue(removedValue)) {
        }
    }
};

// Deque using an array
class ArrayDeque {
private:
    int items[CAPACITY];
    int front;
    int numberOfItems;

public:
    ArrayDeque() {
        front = 0;
        numberOfItems = 0;
    }

    bool isEmpty() {
        return numberOfItems == 0;
    }

    bool insertFront(int value) {
        if (numberOfItems == CAPACITY) {
            return false;
        }

        front = (front - 1 + CAPACITY) % CAPACITY;
        items[front] = value;
        numberOfItems++;
        return true;
    }

    bool insertBack(int value) {
        if (numberOfItems == CAPACITY) {
            return false;
        }

        int position = (front + numberOfItems) % CAPACITY;
        items[position] = value;
        numberOfItems++;
        return true;
    }

    bool removeFront(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        removedValue = items[front];
        front = (front + 1) % CAPACITY;
        numberOfItems--;
        return true;
    }

    bool removeBack(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        int position = (front + numberOfItems - 1) % CAPACITY;
        removedValue = items[position];
        numberOfItems--;
        return true;
    }
};

// Deque using a linked list
class LinkedDeque {
private:
    struct Node {
        int value;
        Node* next;
        Node* previous;
    };

    Node* front;
    Node* rear;

public:
    LinkedDeque() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    bool insertFront(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->previous = nullptr;
        newNode->next = front;

        if (isEmpty()) {
            rear = newNode;
        } else {
            front->previous = newNode;
        }

        front = newNode;
        return true;
    }

    bool insertBack(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;
        newNode->previous = rear;

        if (isEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }

        rear = newNode;
        return true;
    }

    bool removeFront(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        Node* temporary = front;
        removedValue = front->value;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->previous = nullptr;
        }

        delete temporary;
        return true;
    }

    bool removeBack(int& removedValue) {
        if (isEmpty()) {
            return false;
        }

        Node* temporary = rear;
        removedValue = rear->value;
        rear = rear->previous;

        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }

        delete temporary;
        return true;
    }

    ~LinkedDeque() {
        int removedValue;
        while (removeFront(removedValue)) {
        }
    }
};

// Displays the result of each operation
void showResult(const char* operation, bool successful) {
    cout << operation;

    if (successful) {
        cout << " pass";
    } else {
        cout << " failed: structure is empty or full";
    }

    cout << endl;
}

int main() {
    int removedValue;

    cout << "\nArray Stack:\n";
    ArrayStack arrayStack;
    showResult("Remove", arrayStack.pop(removedValue));
    showResult("Insert 10", arrayStack.push(10));
    showResult("Insert 20", arrayStack.push(20));
    showResult("Insert 30", arrayStack.push(30));
    showResult("Remove", arrayStack.pop(removedValue));
    showResult("Insert 40", arrayStack.push(40));
    showResult("Remove", arrayStack.pop(removedValue));
    showResult("Remove", arrayStack.pop(removedValue));
    showResult("Insert 50", arrayStack.push(50));
    showResult("Remove", arrayStack.pop(removedValue));
    showResult("Remove", arrayStack.pop(removedValue));

    cout << "\nLinked Stack:\n";
    LinkedStack linkedStack;
    showResult("Remove", linkedStack.pop(removedValue));
    showResult("Insert 10", linkedStack.push(10));
    showResult("Insert 20", linkedStack.push(20));
    showResult("Insert 30", linkedStack.push(30));
    showResult("Remove", linkedStack.pop(removedValue));
    showResult("Insert 40", linkedStack.push(40));
    showResult("Remove", linkedStack.pop(removedValue));
    showResult("Remove", linkedStack.pop(removedValue));
    showResult("Insert 50", linkedStack.push(50));
    showResult("Remove", linkedStack.pop(removedValue));
    showResult("Remove", linkedStack.pop(removedValue));

    cout << "\nArray Queue:\n";
    ArrayQueue arrayQueue;
    showResult("Remove", arrayQueue.dequeue(removedValue));
    showResult("Insert 10", arrayQueue.enqueue(10));
    showResult("Insert 20", arrayQueue.enqueue(20));
    showResult("Insert 30", arrayQueue.enqueue(30));
    showResult("Remove", arrayQueue.dequeue(removedValue));
    showResult("Insert 40", arrayQueue.enqueue(40));
    showResult("Remove", arrayQueue.dequeue(removedValue));
    showResult("Insert 50", arrayQueue.enqueue(50));
    showResult("Remove", arrayQueue.dequeue(removedValue));
    showResult("Remove", arrayQueue.dequeue(removedValue));
    showResult("Remove", arrayQueue.dequeue(removedValue));

    cout << "\nLinked Queue:\n";
    LinkedQueue linkedQueue;
    showResult("Remove", linkedQueue.dequeue(removedValue));
    showResult("Insert 10", linkedQueue.enqueue(10));
    showResult("Insert 20", linkedQueue.enqueue(20));
    showResult("Insert 30", linkedQueue.enqueue(30));
    showResult("Remove", linkedQueue.dequeue(removedValue));
    showResult("Insert 40", linkedQueue.enqueue(40));
    showResult("Remove", linkedQueue.dequeue(removedValue));
    showResult("Insert 50", linkedQueue.enqueue(50));
    showResult("Remove", linkedQueue.dequeue(removedValue));
    showResult("Remove", linkedQueue.dequeue(removedValue));
    showResult("Remove", linkedQueue.dequeue(removedValue));

    cout << "\nArray Deque:\n";
    ArrayDeque arrayDeque;
    showResult("Remove front", arrayDeque.removeFront(removedValue));
    showResult("Insert back 10", arrayDeque.insertBack(10));
    showResult("Insert front 20", arrayDeque.insertFront(20));
    showResult("Insert back 30", arrayDeque.insertBack(30));
    showResult("Remove front", arrayDeque.removeFront(removedValue));
    showResult("Insert front 40", arrayDeque.insertFront(40));
    showResult("Remove back", arrayDeque.removeBack(removedValue));
    showResult("Insert back 50", arrayDeque.insertBack(50));
    showResult("Remove front", arrayDeque.removeFront(removedValue));
    showResult("Remove back", arrayDeque.removeBack(removedValue));
    showResult("Remove back", arrayDeque.removeBack(removedValue));

    cout << "\nLinked Deque:\n";
    LinkedDeque linkedDeque;
    showResult("Remove front", linkedDeque.removeFront(removedValue));
    showResult("Insert back 10", linkedDeque.insertBack(10));
    showResult("Insert front 20", linkedDeque.insertFront(20));
    showResult("Insert back 30", linkedDeque.insertBack(30));
    showResult("Remove front", linkedDeque.removeFront(removedValue));
    showResult("Insert front 40", linkedDeque.insertFront(40));
    showResult("Remove back", linkedDeque.removeBack(removedValue));
    showResult("Insert back 50", linkedDeque.insertBack(50));
    showResult("Remove front", linkedDeque.removeFront(removedValue));
    showResult("Remove back", linkedDeque.removeBack(removedValue));
    showResult("Remove back", linkedDeque.removeBack(removedValue));

    return 0;
}
