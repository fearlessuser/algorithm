#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int randomAcess(int*nums,int size)
{
    int tmp = rand()%size;
    return nums[tmp];
}

int* extend(int*nums,int size,int enlarge)//有个潜在的问题，原来的nums空间被浪费了
{
    int* newarry = (int*)malloc(sizeof(int)*(size+enlarge));
    for(int i = 0;i<size;i++)
    {
        newarry[i] = nums[i];
    }
    for(int i = size;i<size+enlarge;i++)
    {
        newarry[i] = 0;
    }
    return newarry;
}

void insert(int*nums,int size,int index,int value)
{
    for(int i = size-1;i>index;i--)
    {
        nums[i] = nums[i-1];
    }
    nums[index] = value;
}

void delete(int*nums,int size,int index)
{
    for(int i = index;i<size-1;i++)
    {
        nums[i] = nums[i+1];
    }
}

int find(int*nums,int size,int value)
{
    for(int i = 0;i<size;i++)
    {
        if(nums[i] == value)
        {
            return i;
        }

    }
    return -1;
}

void reversearray(int*nums,int size)
{
    int index = 0;
    for(int i = size-1;i>=0;i++)
    {
        nums[index++] = nums[i];
    }
}

void printarray(int*nums ,int size )
{
    printf("[");
    for(int i = 0;i<size;i++)
    {
        if(i<size-1)
            printf("%d,",nums[i]);
        else
            printf("%d",nums[i]);
    }
    printf("]");
    printf("\n");
}
int main()
{
    int arr[] = {1,2,1,31,4,5,7,8,3,5,97,54,68,2};
    int*p = arr;
    int len = sizeof(arr)/sizeof(int);
    srand(time(NULL));
    int tmp = randomAcess(arr,len);
    printf("%d\n",tmp);
    printarray(arr,len);
    p = extend(arr,len,10);
    printarray(p,len+10);
    insert(p,len,3,100);
    printarray(p,len+10);
    delete(p,len,3);
    printarray(p,len+10);
    tmp = find(p,len,31);
    printf("%d",tmp);

    return 0;
}