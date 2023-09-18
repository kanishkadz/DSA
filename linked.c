#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node N;
N *start=NULL, *ptr, *tmp;
void CreateList();
void PrintList();

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

void main()
{
    int ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Create List");
        printf("\n2 --> Print List");
        printf("\n0 --> Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: CreateList(); break;
            case 2: PrintList(); break;
        }
    } while (ch!=0);
}
