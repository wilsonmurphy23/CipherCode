
#include <iostream>
#include "Queue.h"
#include <cstdlib>

using namespace std;
//************************
// Constructor.          *
//************************
//int count;
//int nodeCount;

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

//************************
// Destructor.           *
//************************
Queue::~Queue() {
    QueueNode *garbage = front;
    while (garbage != nullptr) {
        front = front->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = front;
    }
}

//********************************************
// Function enqueue inserts the value in num *”
// at the rear of the queue.                 *
//********************************************
void Queue::enqueue(int num) {
    if ((nodeCount < 100) && (!isFull())) {
        if (isEmpty()) {
            front = new QueueNode(num);
            rear = front;
        } else {
            rear->next = new QueueNode(num);
            rear = rear->next;
        }
        nodeCount++;
        // cout << "nodeCount is " << nodeCount << endl;
    } else {
        cout << "you tried to queue over 100";

    }


}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void Queue::dequeue(int &num) {
    QueueNode *temp = nullptr;
    if (isEmpty()) {
        cout << "The queue is empty.\n";
        exit(1);
    } else {
        num = front->value;
        temp = front;
        front = front->next;
        delete temp;
        nodeCount--;
    }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool Queue::isEmpty() const {
    if (front == nullptr)
        return true;
    else
        return false;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
void Queue::clear() {
    int value;   // Dummy variable for dequeue

    while (!isEmpty())
        dequeue(value);
}

//dont let more than 100 elements be enqueued
bool Queue::isFull() const {
    if (isEmpty())
        return false;
    else if (nodeCount > 99)
        return true;
    else return true;

}

