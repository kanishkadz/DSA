#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct NOde *next;
};
typedef struct Node N;
N *start=NULL, *ptr, *tmp;
void CreateList();
void PrintList();

void CreateList()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter value:");
    scanf("%d",&ptr->val);
    if(start==NULL)
    {
        start=ptr;
        tmp=ptr;
        ptr->next=start;
    }
    else
    {
        tmp->next=ptr;
        tmp=ptr;
        ptr->next=start;
    }
}

void PrintList()
{
    if(start==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    ptr=start;
    while(ptr->next!=start)
    {
        printf("%d -> ",ptr->val);
        ptr=ptr->next;
    }
    printf("%d ",ptr->val);
}

void main()
{
    int ch;
    do
    {
        printf("\n-: M E N U:-");
        printf("\n1 --> Create List");
        printf("\n2 --> Print List");
        printf("\n0 --> Exit");
        printf("\nEnter Your Choice:");
        switch(ch)
        {
            case 1: CreateList(); break;
            case 2: PrintList(); break;
        }
    }while(ch!=0); 
}