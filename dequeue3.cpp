#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int data[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Enqueue (add) an element to the queue
    void enqueue(int value) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue overflow, cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        data[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue (remove) an element from the queue
    bool dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow, cannot dequeue." << endl;
            return false;
        }

        cout << "Dequeued: " << data[front] << endl;

        if (front == rear) {
            // Last element is dequeued
            front = rear = -1;
        } else {
            front++;
        }

        return true;
    }

    // Access the front element without dequeuing
    void frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element: " << data[front] << endl;
        }
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.frontElement();

    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.frontElement();

    myQueue.dequeue(); // This will cause underflow

    return 0;
}





