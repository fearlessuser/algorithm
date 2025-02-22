#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* newListNode(int val)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->next = NULL;
    node->val = val;
    return node;
}

ListNode* Insert(ListNode* n0,ListNode* p)
{
    p->next = n0->next;
    n0->next = p;
    return n0;
}

ListNode* RemoveListNode(ListNode* n0)
{
    if(n0 == NULL|n0->next == NULL)
    {
        return NULL;
    }
    ListNode*pre = n0->next;
    n0->next = n0->next->next;
    free(pre);
}

ListNode* FindListNodeIndex(ListNode* n0,int index)
{
    ListNode* tmp = n0;
    while(tmp&&index--)
    {
        tmp = tmp->next;
    }
    return tmp;
}
int FindListNodeValue(ListNode* n0,int value)
{
    if(n0 == NULL)
    {
        return -1;
    }
    ListNode* cur = n0;
    int index = 0;
    while(cur)
    {
        if(cur->val == value)
        {
            break;
        }
        cur = cur->next;
        index++;
    }
    return index;
}

void printListNode(ListNode*n0)
{
    if(n0 == NULL)
    {
        return ;
    }
    while(n0->next)
    {
        printf("%d -> ",n0->val);
        n0 = n0->next;
    }
    printf("%d\n",n0->val);
}
int main()
{
    ListNode* n0 = newListNode(1);
    ListNode* n1 = newListNode(2);
    ListNode* n2 = newListNode(3);
    ListNode* n3 = newListNode(4);
    ListNode* n4 = newListNode(5);
    ListNode* n5 = newListNode(6);

    Insert(n0,n1);
    Insert(n0,n2);
    Insert(n0,n3);
    Insert(n0,n4);
    Insert(n0,n5);
    printListNode(n0);
    RemoveListNode(n0);
    printListNode(n0);
    ListNode* nn = FindListNodeIndex(n0,3);
    printf("nn:%d\n",nn->val);
    int tmp = FindListNodeValue(n0,2);
    printf("tmp:%d\n",tmp);
    return 0;
}
