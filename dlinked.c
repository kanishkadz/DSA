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
void InsertLast();
void InsertAfter();
void InsertBefore();
void DeleteFirst();

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

void InsertLast()
{
    tmp=start;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter value to insert:");
    scanf("%d",&ptr->val);
    ptr->prv=NULL;
    tmp->next=ptr;
}

void InsertAfter()
{
    int val;
    printf("\nEnter the value after which to insert:");
    scanf("%d",&val);
    tmp=start;
    while(tmp->val!=val)
    {
        tmp=tmp->next;
    }
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter the value:");
    scanf("%d",ptr->val);
    ptr->prv=tmp;
    ptr->next=tmp->next;
    tmp->next->prv=ptr;
    tmp->next=ptr;
}

void InsertBefore()
{
    int val;
    printf("\nEnter the value before which to enter:");
    scanf("%d",&val);
    tmp=start;
    while(tmp->next->val!=val)
    {
        tmp=tmp->next;
    }
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter a value:");
    scanf("%d",ptr->val);
    ptr->prv=tmp;
    ptr->next=tmp->next;
    tmp->next=ptr;
}

void DeleteFirst()
{
    tmp=start;
    ptr=tmp->next;
    ptr->prv=NULL;
    start=ptr;
    free(tmp);
}

void main()
{
    int ch;
    do
    {
        printf("\n -: M E N U :-");
        printf("\n1 --> Create node");
        printf("\n2 --> Print node");
        printf("\n3 --> Insert a node at first");
        printf("\n4 --> Insert a node at last");
        printf("\n5 --> Insert after a node");
        printf("\n6 --> Insert before a node");
        printf("\n7 --> Delete first node");
        printf("\n0 --> Exit");
        printf("\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: CreateNode(); break;
            case 2: PrintNode(); break;
            case 3: InsertFirst(); break;
            case 4: InsertLast(); break;
            case 5: InsertAfter(); break;
            case 6: InsertBefore(); break;
            case 7: DeleteFirst(); break;
        }
    } while (ch!=0);
    
}