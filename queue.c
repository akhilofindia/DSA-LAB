//main file
#include "queue.h"

int main() {
    struct Queue queue;
    initialize(&queue);

    // Enqueue elements into the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    // Check if the queue is empty
    printf("Is the queue empty? %s\n", is_empty(&queue) ? "Yes" : "No");

    // Peek at the front element of the queue
    printf("Front element of the queue: %d\n", peek(&queue));

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}

//queue.h file
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100

// Define the queue data structure
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue);

// Function to check if the queue is empty
int is_empty(struct Queue *queue);

// Function to check if the queue is full
int is_full(struct Queue *queue);

// Function to enqueue (push) an element into the queue
void enqueue(struct Queue *queue, int item);

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue);

// Function to peek at the front element of the queue
int peek(struct Queue *queue);

#endif

//queue.c file
#include "queue.h"
#include <stdio.h>

// Function to initialize the queue
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int is_empty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int is_full(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue (push) an element into the queue
void enqueue(struct Queue *queue, int item) {
    if (!is_full(queue)) {
        // Check for duplicates before enqueueing
        for (int i = queue->front; i != (queue->rear + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE) {
            if (queue->items[i] == item) {
                printf("Duplicate element %d. Not enqueuing.\n", item);
                return;
            }
        }

        if (is_empty(queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }

        queue->items[queue->rear] = item;
    } else {
        printf("Queue is full. Cannot enqueue %d\n", item);
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue) {
    if (!is_empty(queue)) {
        int item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return item;
    } else {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 as an error indicator
    }
}

// Function to peek at the front element of the queue
int peek(struct Queue *queue) {
    if (!is_empty(queue)) {
        return queue->items[queue->front];
    } else {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Return -1 as an error indicator
    }
}
