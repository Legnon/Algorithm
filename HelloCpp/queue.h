//
//  queue.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 20..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef queue_h
#define queue_h


#endif /* queue_h */

#define MAX_N 100

int front;
int rear;
int queue[MAX_N];

void queueInit(void)
{
    front = 0;
    rear = 0;
}

int queueIsEmpty(void)
{
    return (front == rear);
}

int queueIsFull(void)
{
    if ((rear + 1) % MAX_N == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int queueEnqueue(int value)
{
    if (queueIsFull())
    {
        printf("queue is full!");
        return 0;
    }
    queue[rear] = value;
    rear++;
    if (rear == MAX_N)
    {
        rear = 0;
    }
    
    return 1;
}

int queueDequeue(int *value)
{
    if (queueIsEmpty())
    {
        printf("queue is empty!");
        return 0;
    }
    *value = queue[front];
    front++;
    if (front == MAX_N)
    {
        front = 0;
    }
    return 1;
}
