#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    struct QueueNode {
        int value;
        QueueNode *next;

        QueueNode(int value1, QueueNode *next1 = nullptr) {
            value = value1;
            next = next1;
        }
        // int key[];
    };

    // These track the front and rear of the queue
    QueueNode *front;
    QueueNode *rear;
public:
    int nodeCount = 0;

    // Constructor and Destructor
    //  int Full = 100;
    Queue();

    ~Queue();

    //  Queue::QueueNode* qSize;
    //Queue::QueueNode* qFull = &Full;
    // Member functions
    void enqueue(int);

    void dequeue(int &);

    bool isEmpty() const;

    bool isFull() const;

    void clear();
};

#endif
