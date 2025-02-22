#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_INT 4
typedef struct ArrayQueue
{
    int* arr;
    int front;
    int queuesize;
    int queuecapacity;
}ArrayQueue;

ArrayQueue* NewArrayQueue()
{
    ArrayQueue* aq1 = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    aq1->arr = (int*)malloc(sizeof(int)*MAX_INT);
    aq1->front = aq1->queuesize = 0;
    aq1->queuecapacity = MAX_INT;
    return aq1;
}

void push(ArrayQueue*aq1,int val)
{
    assert(aq1);
    if(aq1->queuesize == aq1->queuecapacity)
    {
        printf("队列已满\n");
        return;
    }
    int rear = (aq1->front+aq1->queuesize)%aq1->queuecapacity;
    aq1->arr[rear] = val;
    aq1->queuesize++;
}
int pop(ArrayQueue*aq1)
{
    assert(aq1);
    int front = aq1->front;
    aq1->front = (aq1->front+1)%aq1->queuecapacity;
    aq1->queuesize--;
    return aq1->arr[front];
}

int peek(ArrayQueue*aq1)
{
    assert(aq1);
    return aq1->arr[aq1->front];
}

void print(ArrayQueue*aq1)
{
    assert(aq1);
    int index = 0;
    for(int i = 0;i<aq1->queuesize;i++)
    {
        index = (aq1->front+i)%aq1->queuecapacity;
        printf("%d,",aq1->arr[index]);
    }
    printf("\n");
}
int main()
{
    ArrayQueue*aq1 = NewArrayQueue();
    push(aq1,10);
    push(aq1,20);
    push(aq1,30);
    push(aq1,40);
    print(aq1);
    pop(aq1);
    pop(aq1);
    print(aq1);
    push(aq1,90);
    push(aq1,90);
    push(aq1,90);
    print(aq1);
    return 0;
}
