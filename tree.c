#include<stdio.h>
#include<malloc.h>
struct Tnode
{
    int info;
    struct Tonde *LC;
    struct Tnode *RC;
};
typedef struct Tnode T;
T *Tree=NULL;
T *Create_Tree(int, T*);
void Display_Tree(T*,int);

T* Create_Tree(int info, T* node)
{
    if(node==NULL)
    {
        node=(T*)malloc(sizeof(T));
        node->info=info;
        node->LC=NULL;
        node->RC=NULL;
        return(node);
    }
    if(node->info>=info)
    {
        node->LC=Create_Tree(info,node->LC);
    }
    else
    {
        node->RC=Create_Tree(info,node->RC);
    }
}
