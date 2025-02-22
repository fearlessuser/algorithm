#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_INT 100
typedef struct ArrayDqueue
{
    int*arr;
    int front;
    int queuesize;
    int queuecapacity;
}ArrayDqueue;

ArrayDqueue* NewArrayDqueue()
{
    ArrayDqueue*dq1 = (ArrayDqueue*)malloc(sizeof(ArrayDqueue));
    dq1->queuecapacity = MAX_INT;
    dq1->arr = (int*)malloc(sizeof(int)*dq1->queuecapacity);
    dq1->front = 0;
    dq1->queuesize = 0;
    return dq1;
}

int size(ArrayDqueue*dq1)
{
    assert(dq1);
    return dq1->queuesize;
}

int capacity(ArrayDqueue*dq1)
{
    assert(dq1);
    return dq1->queuecapacity;
}

int peek(ArrayDqueue*dq1)
{
    assert(dq1);
    return dq1->arr[dq1->front];
}
int DequeueIndex(ArrayDqueue*dq1,int index)
{
    assert(dq1);
    return (index+dq1->queuecapacity)%dq1->queuecapacity;
}
void delqueue(ArrayDqueue*dq1)
{
    assert(dq1);
    free(dq1->arr);
    free(dq1);
}
void pushfront(ArrayDqueue*dq1,int val)
{
    assert(dq1);
    if(dq1->queuesize == dq1->queuecapacity)
    {
        printf("队列已满\n");
        return ;
    }
    int front = DequeueIndex(dq1,dq1->front-1);
    dq1->arr[front] = val;
    dq1->front = front;
    dq1->queuesize++;
}

void pushrear(ArrayDqueue*dq1,int val)
{
    assert(dq1);
    if(dq1->queuesize == dq1->queuecapacity)
    {
        printf("队列已满\n");
        return ;
    }
    int rear = DequeueIndex(dq1,dq1->queuesize+dq1->front);
    dq1->arr[rear] = val;
    dq1->queuesize++;
}

int popfront(ArrayDqueue*dq1)
{
    assert(dq1);
    int tmp = dq1->front;
    int front = DequeueIndex(dq1,dq1->front+1);
    dq1->queuesize--;
    dq1->front = front;
    return dq1->arr[tmp];
}

int poprear(ArrayDqueue*dq1)
{
    assert(dq1);
    int rear = DequeueIndex(dq1,dq1->front-1+dq1->queuesize);
    dq1->queuesize--;
    return dq1->arr[rear];

}
//这里要特别小心当dq1->front临近队尾而rear在队首时的情况
void print(ArrayDqueue*dq1)
{
    assert(dq1);
    int index = 0;
    for(int i = 0;i<dq1->queuesize;i++)
    {
        index = DequeueIndex(dq1,dq1->front+i);
        printf("%d, ",dq1->arr[index]);
    }
}
int main()
{
    ArrayDqueue*dq1 = NewArrayDqueue();
    pushfront(dq1,10);
    print(dq1);
    pushfront(dq1,20);
    pushfront(dq1,30);
    pushrear(dq1,40);
    pushrear(dq1,50);
    print(dq1);
    delqueue(dq1);
    return 0;
}