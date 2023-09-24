#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node N;
N *start=NULL, *ptr, *tmp, *prv;
void CreateList();
void PrintList();
void InsertFirst();
void InsertLast();
void InsertBefore();
void Count();
void Search();
void DeleteFirst();
void DeleteLast();
void DeleteAfter();

void CreateList()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter Value:");
    scanf("%d",&ptr->val);
    ptr->next=NULL;
    if(start==NULL)
    {
        tmp=ptr;
        start=ptr;
    }
    else
    {
        tmp->next=ptr;
        tmp=ptr;
    }
}

void PrintList()
{
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->val);
        ptr=ptr->next;
    }
}

void InsertFirst()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter the value to insert at first:");
    scanf("%d",&ptr->val);
    ptr->next=start;
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
    printf("\nEnter value to insert at last:");
    scanf("%d",&ptr->val);
    tmp->next=ptr;
    ptr->next=NULL;
}

void InsertBefore()
{
    int val;
    printf("\nEnter the value before which to insert:");
    scanf("%d",&val);
    tmp=start;
    while(tmp->next->val!=val)
    {
        tmp=tmp->next;
    }
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter the value to insert:");
    scanf("%d",&ptr->val);
    tmp->next=ptr;
}

void Count()
{
    int c=0;
    tmp=start;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
        c++;
    }
    printf("\nThe number of nodes are %d",c+1);
}

void Search()
{
    int val,c=0,flag=0;
    printf("\nEnter the value to search:");
    scanf("%d",&val);
    tmp=start;
    while(tmp->val!=val)
    {
        c++;
        tmp=tmp->next;
    }
    flag=1;
    if(flag==1)
        printf("\nNode found at %d",c+1);
    else
        printf("\nNode not found !!");
}

void DeleteFirst()
{
    ptr=start;
    start=start->next;
    free(ptr);
}

void DeleteLast()
{
    ptr=start;
    while(ptr->next!=NULL)
    {
        prv=ptr;
        ptr=ptr->next;
    }
    prv->next=NULL;
    free(ptr);
}

void DeleteAfter()
{
    int val;
    ptr=start;
    printf("\nEnter the value after which to delete:");
    scanf("%d",&val);
    while(ptr->val!=val)
    {
        ptr=ptr->next;
    }
    tmp=ptr->next;
    ptr->next=tmp->next;
    free(tmp);
}

void main()
{
    int ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Create List");
        printf("\n2 --> Print List");
        printf("\n3 --> Insert at First");
        printf("\n4 --> Insert at Last");
        printf("\n5 --> Insert before any node");
        printf("\n6 --> Count a node");
        printf("\n7 --> Search a node");
        printf("\n8 --> Delete first node");
        printf("\n9 --> Delete last node");
        printf("\n10 --> Delete after a node");
        printf("\n0 --> Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: CreateList(); break;
            case 2: PrintList(); break;
            case 3: InsertFirst(); break;
            case 4: InsertLast(); break;
            case 5: InsertBefore(); break;
            case 6: Count(); break;
            case 7: Search(); break;
            case 8: DeleteFirst(); break;
            case 9: DeleteLast(); break;
            case 10: DeleteAfter(); break;
        }
    } while (ch!=0);
}
