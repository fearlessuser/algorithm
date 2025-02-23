#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
typedef struct ArrayGraph
{
    int graph[MAX_SIZE][MAX_SIZE];
    int vertices[MAX_SIZE];
    int size;
}ArrayGraph;

ArrayGraph* NewGraph()
{
    ArrayGraph* agraph = malloc(sizeof(ArrayGraph));
    agraph->size = 0;
    for(int i = 0;i<MAX_SIZE;i++)
    {
        for(int j = 0;j<MAX_SIZE;j++)
        {
            agraph->graph[i][j] = 0;
        }
    }
    return agraph;
}

void delGraph(ArrayGraph*agraph)
{
    free(agraph);
}

int size(ArrayGraph*agraph)
{
    return agraph->size;
}

void addvertex(ArrayGraph*agraph,int val)
{
    if (agraph->size == MAX_SIZE) {
        fprintf(stderr, "图的顶点数量已达最大值\n");
        return;
    }
    agraph->vertices[agraph->size++] = val;

}

void removevertex(ArrayGraph*agraph,int index)
{
    if(index<0||index>=agraph->size)
    {
        fprintf(stderr, "顶点索引越界\n");
        return;
    }
    for(int i = index;i<agraph->size-1;i++)
    {
        agraph->vertices[i] = agraph->vertices[i+1];
    }
    for(int i = index;i<agraph->size-1;i++)
    {
        for(int j = 0;j<agraph->size;j++)
        {
            agraph->graph[i][j] = agraph->graph[i+1][j];
        }
    }

    for(int i = index;i<agraph->size-1;i++)
    {
        for(int j = 0;j<agraph->size;j++)
        {
            agraph->graph[j][i] = agraph->graph[j][i+1];
        }
    }
    agraph->size--;
}

void addedge(ArrayGraph*agraph,int i,int j)
{
    if(i<0||i>=agraph->size||j<0||j>=agraph->size)
    {
        fprintf(stderr, "顶点索引越界\n");
        return;
    }
    agraph->graph[i][j] = agraph->graph[j][i] = 1;
    
}

void deledge(ArrayGraph*agraph,int i,int j)
{
    if(i<0||i>=agraph->size||j<0||j>=agraph->size)
    {
        fprintf(stderr, "顶点索引越界\n");
        return;
    }
    agraph->graph[i][j] = agraph->graph[j][i] = 0;
}

void print(ArrayGraph*agraph)
{
    printf("打印顶点列表:");
    for(int i = 0;i<agraph->size;i++)
    {
        printf("%d ",agraph->vertices[i]);
    }
    printf("\n");
    printf("打印图的边:\n");
    for(int i = 0;i<agraph->size;i++)
    {
        for(int j = 0;j<agraph->size;j++)
        {
            printf("%d ",agraph->graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    ArrayGraph* agraph = NewGraph();
    addvertex(agraph,10);
    addvertex(agraph,20);
    addvertex(agraph,30);
    addvertex(agraph,40);
    // print(agraph);
    addedge(agraph,0,1);
    addedge(agraph,1,2);
    addedge(agraph,2,3);
    print(agraph);
    removevertex(agraph,1);
    print(agraph);
    delGraph(agraph);
    print(agraph);
}