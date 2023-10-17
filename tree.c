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

void Display_Tree(T *Tree,int L)
{
    int i;
    if(Tree)
    {
        Display_Tree(Tree->RC,L+1);
        printf("\n");
        for(i=0;i<L;i++)
        {
            printf(" ");
        }
        printf("%d",Tree->info);
        printf("\n");
        Display_Tree(Tree->Lc,L+1);
    }
}

void main()
{
    int info;
    char ch;
    do
    {
        printf("\nInput Information:");
        scanf("%d",&info); fflush(stdin);
        Tree=Create_Tree(info, Tree);
        printf("\nTree is now:-\n");
        Display_Tree(Tree,1);
        printf("\nContinue ?:");
        scanf("%c",&ch);fflush(stdin);
    } while(ch!="n");
}

void Preorder(T *Tree)
{
    if(Tree)
    {
        printf("%d ",Tree->info);
        Preorder(Tree->LC);
        Preorder(Tree->RC);
    }
}