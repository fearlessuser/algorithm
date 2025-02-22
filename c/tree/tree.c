#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
typedef struct TreeNode
{
    int value;
    int height;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* NewTreeNode(int val)
{
    TreeNode* tNode = malloc(sizeof(TreeNode));
    tNode->right = tNode->left = NULL;
    tNode->height = 0;
    tNode->value = val;
    return tNode;
}

int* bfs(TreeNode* root,int*size)
{
    assert(root);
    int front,rear;
    int index,*arr;
    TreeNode* node;
    TreeNode** queue;

    front = rear = 0;
    queue = (TreeNode**)malloc(sizeof(TreeNode*)*MAX_SIZE);
    queue[rear++] = root;
    arr = (int*)malloc(sizeof(int)*MAX_SIZE);
    index = 0;
    while(rear>front)
    {
        node = queue[front++];
        arr[index++] = node->value;
        if(node->left!=NULL)
        {
            queue[rear++] = node->left;
        }
        if(node->right!=NULL)
        {
            queue[rear++] = node->right;
        }
    }
    *size = index;
    arr = realloc(arr,sizeof(int)*index);
    free(queue);
    return arr;   
}

void PreOrder(TreeNode*root,int*size)
{
    if(root == NULL)
        return;
    arr[(*size)++] = root->value;
    PreOrder(root->left,size);
    PreOrder(root->right,size);
}
void MidOrder(TreeNode*root,int*size)
{
    if(root == NULL)
        return;
    PreOrder(root->left,size);
    arr[(*size)++] = root->value;
    PreOrder(root->right,size);
}
void PostOrder(TreeNode*root,int*size)
{
    if(root == NULL)
        return;
    PreOrder(root->left,size);
    PreOrder(root->right,size);
    arr[(*size)++] = root->value;
}
void printarr(int*arr1,int size)
{
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
}
int main()
{
    TreeNode*n0 = NewTreeNode(1);
    TreeNode*n1 = NewTreeNode(2);
    TreeNode*n2 = NewTreeNode(3);
    TreeNode*n3 = NewTreeNode(4);
    TreeNode*n4 = NewTreeNode(5);
    TreeNode*n5 = NewTreeNode(6);
    TreeNode*n6 = NewTreeNode(7);

    n0->left = n1;
    n0->right = n4;
    n1->left = n2;
    n1->right = n3;
    n4->left = n5;
    n4->right = n6;

    int size = 0;
    MidOrder(n0,&size);
    printarr(arr,size);
    size = 0;
    PreOrder(n0,&size);
    printarr(arr,size);
    size = 0;
    PostOrder(n0,&size);
    printarr(arr,size);

}