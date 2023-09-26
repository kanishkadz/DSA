#include<stdio.h>
#include<malloc.h>
struct Node
{
    int val;
    struct Node *prv;
    struct Node *next;
};
typedef struct Node N;
N *start=NULL, *ptr, *tmp;
void CreateNode();
void PrintNode();
void InsertFirst();

void CreateNode()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter Value:");
    scanf("%d",&ptr->val);
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
        ptr->prv=NULL;
        tmp=ptr;
    }
    else
    {
        tmp->next=ptr;
        ptr->prv=tmp;
        tmp=ptr;
    }
}

void PrintNode()
{
    ptr=start;
    while(ptr->next!=NULL)
    {
        printf("%d-> ",ptr->val);
        ptr=ptr->next;
    }
    while(ptr!=NULL)
    {
        printf("%d <-",ptr->val);
        ptr=ptr->prv;
    }
}

void InsertFirst()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter value to insert:");
    scanf("%d",&ptr->val);
    ptr->next=start;
    ptr->prv=NULL;
    start->prv=ptr;
    start=ptr;
}

void main()
{
    int ch;
    do
    {
        printf("\n -: M E N U :-");
        printf("\n1 --> Create Node");
        printf("\n2 --> Print Node");
        printf("\n0 --> Exit");
        printf("\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: CreateNode(); break;
            case 2: PrintNode(); break;
        }
    } while (ch!=0);
    
}