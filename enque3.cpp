#include <iostream>
#include <cstdlib>

#define MAX_SIZE 5

class Queue {
private:
    int capacity;
    int* queue;
    int front;
    int rear;
    int size;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->queue = new int[capacity];
        this->front = 0;
        this->rear = -1;
        this->size = 0;
    }

    ~Queue() {
        delete[] queue;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int data) {
        if (isFull()) {
            std::cerr << "Queue overflow error. Exiting." << std::endl;
            exit(EXIT_FAILURE);
        }

        rear = (rear + 1) % capacity;
        queue[rear] = data;
        size++;

        std::cout << "Enqueued " << data << " successfully." << std::endl;
    }
};

int main() {
    // Set the capacity of the queue
    int capacity = MAX_SIZE;

    // Create a queue
    Queue myQueue(capacity);

    // Enqueue elements into the queue
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    // Try to enqueue when the queue is full (uncomment the next line to test)
    // myQueue.enqueue(6);

    return 0;
}

