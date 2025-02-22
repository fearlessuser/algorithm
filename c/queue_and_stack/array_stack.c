#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define MAX_INT 100

typedef struct ArrayStack
{
    int*arr;
    int size;
}ArrayStack;

ArrayStack* NewArrayStack()
{
    ArrayStack* as1 = (ArrayStack*)malloc(sizeof(ArrayStack));
    as1->arr = (int*)malloc(sizeof(int)*MAX_INT);
    as1->size = 0;
    return as1;
}

void delete(ArrayStack*as1)
{
    assert(as1);
    free(as1->arr);
    free(as1);
}

void push(ArrayStack* as1,int val)
{
    assert(as1);
    as1->arr[as1->size++] = val;
}

int pop(ArrayStack*as1)
{
    assert(as1);
    int tmp = as1->arr[as1->size-1];
    as1->size--;
    return tmp;
}

int peek(ArrayStack*as1)
{
    assert(as1);
    return as1->arr[as1->size-1];
}

int print(ArrayStack* as1)
{
    for(int i = 0;i<as1->size-1;i++)
    {
        printf("%d, ",as1->arr[i]);
    }
    printf("%d",as1->arr[as1->size-1]);
    printf("\n");
}

int main()
{
    ArrayStack*as1 = NewArrayStack();
    push(as1,10);
    push(as1,20);
    push(as1,30);
    push(as1,40);
    push(as1,50);
    push(as1,90);
    print(as1);
    pop(as1);
    pop(as1);
    pop(as1);
    print(as1);
    delete(as1);
}