#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct Pair
{
    int key;
    char*str;
}Pair;

typedef struct HashMap
{
    Pair* buckets[MAX_SIZE];
}HashMap;

typedef struct MapSet
{
    void* set;
    int len;
}MapSet;

int hash(int key)
{
    return key%MAX_SIZE;
}

HashMap* NewHashMap()
{
    HashMap* map = malloc(sizeof(HashMap));
    for(int i = 0;i<MAX_SIZE;i++)
    {
        map->buckets[i] = NULL;
    }
    return map;
}

void delHashMap(HashMap*map)
{
    for(int i = 0;i<MAX_SIZE;i++)
    {
        if(map->buckets[i]!=NULL)
        {
            free(map->buckets[i]->str);
            free(map->buckets[i]);
        }
        
    }
    free(map);
}

char* get(HashMap*map,int key)
{
    int index = hash(key);
    if(map->buckets[index])
        return map->buckets[index]->str;
}

void put(HashMap*map,int key,char* value)
{
    Pair* p = malloc(sizeof(Pair));
    p->key = key;
    p->str = malloc(strlen(value)+1);
    strcpy(p->str,value);
    int index = hash(key);
    if(map->buckets[index]!=NULL)
    {
        return;
    }
    map->buckets[index] = p;
}

void RemoveItem(HashMap* map,int key)
{
    int index = hash(key);
    if(map->buckets[index] == NULL)
    {
        printf("当前的key值无元素可删\n");
        return;
    }
    free(map->buckets[index]->str);
    free(map->buckets[index]);
    map->buckets[index] = NULL;
}

void getpair(HashMap*map,MapSet* set)
{
    int total = 0;
    int index = 0;
    for(int i = 0;i<MAX_SIZE;i++)
    {
        
        if (map->buckets[i]!=NULL)
        {
            total++;
        }
    }
    Pair* entries = malloc(sizeof(Pair)*total);
    for(int i = 0;i<MAX_SIZE;i++)
    {
        if(map->buckets[i] != NULL)
        {
            entries[index].key = map->buckets[i]->key;
            entries[index].str = malloc(strlen(map->buckets[i]->str)+1);
            strcpy(entries->str,map->buckets[i]->str);
            index++;
       
        }
    }
    set->set = entries;
    set->len = total;
}

void getkey(HashMap*map,MapSet *set)
{
    int total = 0;
    int index = 0;
    for(int i = 0;i<MAX_SIZE;i++)
    {
        
        if (map->buckets[i]!=NULL)
        {
            total++;
        }
    }
    int* entries = malloc(sizeof(int)*total);
    for(int i = 0;i<MAX_SIZE;i++)
    {
        if(map->buckets[i] != NULL)
        {
            entries[index++] = map->buckets[i]->key;
       
        }
    }
    set->set = entries;
    set->len = total;
}

void getvalue(HashMap* map,MapSet* set)
{
    int total = 0;
    int index = 0;
    for(int i = 0;i<MAX_SIZE;i++)
    {
        
        if (map->buckets[i]!=NULL)
        {
            total++;
        }
    }
    char** entries = malloc(sizeof(char*)*total);
    for(int i = 0;i<MAX_SIZE;i++)
    {
        if(map->buckets[i] != NULL)
        {
            entries[index] = malloc(strlen(map->buckets[i]->str)+1);
            strcpy(entries[index],map->buckets[i]->str);
            index++;
       
        }
    }
    set->set = entries;
    set->len = total;
}

void print(HashMap*map)
{
    for(int i = 0;i<MAX_SIZE;i++)
    {
        if(map->buckets[i] != NULL)
        {
            printf("key:%d , value:%s\n",map->buckets[i]->key,map->buckets[i]->str);
        }
    }
}

int main()
{
    HashMap*hp1 = NewHashMap();
    put(hp1, 12836, "小哈");
    put(hp1, 15937, "小啰");
    put(hp1, 16750, "小算");
    put(hp1, 13276, "小法");
    put(hp1, 10583, "小鸭");
    put(hp1,100,"张本璟");
    put(hp1,30,"张三");
    print(hp1);
    RemoveItem(hp1,100);
    char* s1 = get(hp1,12836);
    printf("%d->%s\n",12836,s1);

    MapSet* ms1 = malloc(sizeof(MapSet));
    getkey(hp1,ms1);
    int* keys = (int*)ms1->set;
    for(int i = 0;i<ms1->len;i++)
    {
        printf("%d\n",keys[i]);
    }
    
}