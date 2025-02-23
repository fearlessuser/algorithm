#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
typedef struct ArrayTree
{
    int*arr;
    int size;
}ArrayTree;

ArrayTree* NewArrayTree(int*arr,int arrsize)
{
    ArrayTree* atree = malloc(sizeof(ArrayTree));
    atree->arr = malloc(sizeof(int)*arrsize);
    memcpy(atree->arr,arr,arrsize*sizeof(int));
    atree->size = arrsize;
    return atree;
}

void delArrayTree(ArrayTree* atree)
{
    assert(atree);
    free(atree->arr);
    free(atree);
}

int size(ArrayTree* atree)
{
    assert(atree);
    return atree->size;
}
int val(ArrayTree*atree,int index)
{
    if(index<0|index>=atree->size)
    {
        return INT_MAX;
    }
    return atree->arr[index];
}
int left(int index)
{
    return index*2+1;
}
int right(int index)
{
    return index*2+2;
}
int parent(int index)
{
    return (index-1)/2;
}

int* LevelOrder(ArrayTree*atree,int*returnsize)
{   
    int*arr = malloc(sizeof(int)*atree->size);
    int index = 0;
    for(int i = 0;i<atree->size;i++)
    {
        if(atree->arr[i] !=INT_MAX)
        {
            arr[index++] = atree->arr[i];
        }
    }
    *returnsize = index;
    return arr;
}

void dfs(ArrayTree*atree,int i,char* str,int* res,int*index)
{
    if(val(atree,i) == INT_MAX)
        return;
    if(strcmp(str,"pre") == 0)
    {
        res[(*index)++] = val(atree,i);
    }
    dfs(atree,left(i),str,res,index);
    if(strcmp(str,"in") == 0)
    {
        res[(*index)++] = val(atree,i);
    }
    dfs(atree,right(i),str,res,index);
    if(strcmp(str,"post") == 0)
    {
        res[(*index)++] = val(atree,i);
    }   
}

int* preOrder(ArrayTree*atree,int*returnsize)
{
    int* res = malloc(sizeof(int)*atree->size);
    int index = 0;
    dfs(atree,0,"pre",res,&index);
    *returnsize = index;
    return res;
}

int* inOrder(ArrayTree*atree,int*returnsize)
{
    int* res = malloc(sizeof(int)*atree->size);
    int index = 0;
    dfs(atree,0,"in",res,&index);
    *returnsize = index;
    return res;
}

int* postOrder(ArrayTree*atree,int*returnsize)
{
    int* res = malloc(sizeof(int)*atree->size);
    int index = 0;
    dfs(atree,0,"post",res,&index);
    *returnsize = index;
    return res;
}

void PrintArray(int*arr,int size)
{
    printf("[");
    for(int i = 0;i<size-1;i++)
    {
        if(arr[i] != INT_MAX)
        {
            printf("%d, ",arr[i]);
        }
    }
    printf("%d",arr[size-1]);
    printf("]\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    ArrayTree* atree =  NewArrayTree(arr,arrSize);

    printf("%d\n",val(atree,3));
    printf("%d\n",parent(11));

    int*res;
    int returnsize;
    res = LevelOrder(atree,&returnsize);
    PrintArray(res,returnsize);
    res = preOrder(atree,&returnsize);
    PrintArray(res,returnsize);
    res = inOrder(atree,&returnsize);
    PrintArray(res,returnsize);
    res = postOrder(atree,&returnsize);
    PrintArray(res,returnsize);
}

