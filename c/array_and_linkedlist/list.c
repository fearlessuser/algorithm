#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct List
{
    int* arr;
    int size;
    int capacity;
    int extendrtio;
}List;

List* NewList(int c1)
{
    List* list1 = (List*)malloc(sizeof(List));
    list1->arr = (int*)malloc(sizeof(int)*c1);
    list1->capacity = c1;
    list1->size = 0;
    list1->extendrtio = 2;
    return list1;
}

int ListSize(List* list)
{
    return list->size;
}

int ListCapacity(List* list)
{
    return list->capacity;
}

void delList(List* list)
{
    assert(list);
    free(list->arr);
    free(list);
}

void ExendCapacity(List* list)
{
    int newcapacity = list->extendrtio*list->capacity;
    int* extend = (int*)malloc(sizeof(int)*newcapacity);
    for(int i =0;i<list->size;i++)
    {
        extend[i] = list->arr[i];
    }
    
    list->arr = extend;
    list->capacity = newcapacity;
}

int GetList(List* list,int index)
{
    assert(index>=0&&index<list->size);
    return list->arr[index];
}

int SetList(List*list,int index,int value)
{
    assert(index>=0&&index<list->size);
    list->arr[index] = value;
}

int InsertList(List*list,int index,int value)
{
    assert(index>=0&&index<list->size);
    if(list->size == list->capacity)
    {
        ExendCapacity(list);
    }
    for(int i = list->size-1;i>=index;i--)
    {
        list->arr[i+1] = list->arr[i];
    }
    list->arr[index] = value;
    list->size++;
}

int AddList(List*list,int val)
{
    if(list->size == list->capacity)
    {
        ExendCapacity(list);
    }
    list->arr[list->size++] = val;
}

int DelListItem(List*list,int index)
{
    assert(index>=0&&index<list->size);
    for(int i = index;i<list->size-1;i++)
    {
        list->arr[i] = list->arr[i+1];
    }

}
void printList(List*list)
{
    printf("[");
    for(int i = 0;i<list->size-1;i++)
    {
        printf("%d, ",list->arr[i]);
    }
    printf("%d",list->arr[list->size-1]);
    printf("]\n");

}

int main()
{
    List* lst1 = NewList(2);
    AddList(lst1,1);
    AddList(lst1,2);
    AddList(lst1,3);
    AddList(lst1,4);
    AddList(lst1,5);
    AddList(lst1,6);
    AddList(lst1,7);
    printList(lst1);
    InsertList(lst1,2,100);
    printList(lst1);
    DelListItem(lst1,5);
    printList(lst1);
    SetList(lst1,3,1000);
    printList(lst1);
    printf("%d",lst1->capacity);
    
}