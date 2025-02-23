#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 100
typedef struct Heap
{
    int arr[MAX_SIZE];
    int size;
}Heap;
void sitdown(Heap*hp,int i);
int parent(int i);
Heap* NewHeap(int*arr,int size)
{
    Heap* hp = malloc(sizeof(Heap));
    memcpy(hp->arr,arr,sizeof(int)*size);
    hp->size = size;
    for(int i = parent(hp->size-1);i>=0;i--)
    {
        sitdown(hp,i);
    }
    
    return hp;
}
void delHeap(Heap*hp)
{
    free(hp);
}

int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}

int parent(int i)
{
    return (i-1)/2;
}
void swap(Heap*hp,int i,int j)
{
    int tmp = hp->arr[i];
    hp->arr[i] = hp->arr[j];
    hp->arr[j] = tmp;
}

bool isempty(Heap*hp)
{
    return hp->size == 0;
}
int size(Heap*hp)
{
    return hp->size;
}
int peek(Heap*hp)
{
    return hp->arr[0];
}
void situp(Heap*hp,int i)
{
    int max = i;
    while(true)
    {
        if(max<0||hp->arr[max]<=hp->arr[parent(max)])
        {
            break;
        }
        swap(hp,max,parent(max));
        max = parent(max);
    }
}
void push(Heap* hp,int val)
{
    if(hp->size == MAX_SIZE)
    {
        return;
    }
    hp->arr[hp->size] = val;
    hp->size++;
    situp(hp,hp->size-1);

}

void sitdown(Heap*hp,int i)
{
    while(true)
    {   
        int max = i;   
        int l = left(i);
        int r = right(i);
        if(l<hp->size&&hp->arr[l]>hp->arr[max])
        {
            max = l;
        }
        if(r<hp->size&&hp->arr[r]>hp->arr[max])
        {
            max = r;
        }
        if(max == i)
        {
            break;
        }
        swap(hp,max,i);
        i = max;     
    }
}

int pop(Heap*hp)
{
    if(isempty(hp))
    {
        printf("堆已空\n");
        return INT_MAX;
    }
    int val = hp->arr[0];
    swap(hp,0,hp->size-1);
    hp->size--;
    sitdown(hp,0);
    return val;
}
void print(Heap*hp)
{
    printf("[");
    for(int i = 0;i<hp->size-1;i++)
    {
        printf("%d, ",hp->arr[i]);
    }
    printf("%d",hp->arr[hp->size-1]);
    printf("]\n");

}
int main()
{
    int arr[] = {1,23,3,4,5,6,7,8,9,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    Heap*hp = NewHeap(arr,len);
    print(hp);
    push(hp,100);
    print(hp);
    pop(hp);
    print(hp);
    printf("堆顶元素:%d\n",peek(hp));
    printf("堆的大小:%d\n",size(hp));
    printf("堆为空？:%s\n",isempty(hp)?"true":"false");
    return 0;
}