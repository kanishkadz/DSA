#include <stdio.h>
#include <stdlib.h>

struct Tnode 
{
    int info;
    struct Tnode* LC;
    struct Tnode* RC;
};

typedef struct Tnode T;
T *Tree=NULL;
T* Create_Tree(int info, T* node);
void Display_Tree(T*, int);
void Preorder(T* Tree);
void Inorder(T* Tree);
void Postorder(T* Tree);

T* Create_Tree(int info, T* node) 
{
    if (node == NULL) 
    {
        node = (T*)malloc(sizeof(T));
        node->info = info;
        node->LC = NULL;
        node->RC = NULL;
        return node;
    }
    if (info <= node->info) 
    {
        node->LC = Create_Tree(info, node->LC);
    }
    else 
    {
        node->RC = Create_Tree(info, node->RC);
    }
    return node;
}

void Display_Tree(T* Tree, int L) 
{
    int i;
    if (Tree) 
    {
        Display_Tree(Tree->RC, L + 1);
        for (i = 0; i < L; i++) 
        {
            printf("  "); 
        }
        printf("%d\n", Tree->info);
        Display_Tree(Tree->LC, L + 1);
    }
}

int main() 
{  
    int info;
    char ch;
    do 
    {
        printf("\nInput Information:");
        scanf("%d", &info);
        fflush(stdin);
        Tree = Create_Tree(info, Tree);
        printf("\nTree is now:\n");
        Display_Tree(Tree, 1);
        printf("\nContinue (y/n)?: ");
        scanf(" %c", &ch); 
        fflush(stdin);
    } while (ch != 'n');  
    
    printf("\nPreorder: ");
    Preorder(Tree);
    
    printf("\nInorder: ");
    Inorder(Tree);
    
    printf("\nPostorder: ");
    Postorder(Tree);

    return 0;
}

void Preorder(T* Tree) 
{
    if (Tree) 
    {
        printf("%d ", Tree->info);
        Preorder(Tree->LC);
        Preorder(Tree->RC);
    }
}

void Inorder(T* Tree) 
{
    if (Tree) 
    {
        Inorder(Tree->LC);
        printf("%d ", Tree->info);
        Inorder(Tree->RC);
    }
}

void Postorder(T* Tree) 
{
    if (Tree) 
    {
        Postorder(Tree->LC);
        Postorder(Tree->RC);
        printf("%d ", Tree->info);
    }
}
