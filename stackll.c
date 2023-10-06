//Stack using Linked List
#include<stdio.h>
#include<malloc.h>
struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node N;
N *top=NULL, *ptr;
void push();
void status();

void push()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter value to enter:");
    scanf("%d",&ptr->val);
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
}

void status()
{
    if(top==NULL)
    {
        printf("\nStack Underflow");
        return;
    }
    printf("\nStack is now:");
    ptr=top;
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->val);
        ptr=ptr->next;
    }
}

void main()
{
    int ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Push");
        printf("\n2 --> Status");
        printf("\n0 --> Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(); break;
            case 2:status(); break;
        }
    } while (ch!=0);
}