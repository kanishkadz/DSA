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
void pop();
void peek();

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

void pop()
{
    ptr=top;
    if(top==NULL)
    {
        printf("\nStack Underflow");
        return;
    }
    else
    {
        printf("\n%d is popped",ptr->val);
        top=top->next;
        free(ptr);
    }
}

void peek()
{
    ptr=top;
    if(top==NULL)
    {
        printf("\nStack Underflow");
        return;
    }
    else
    {
        printf("\nTop Value is: %d",ptr->val);
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
        printf("\n3 --> Pop");
        printf("\n4 --> Peek");
        printf("\n0 --> Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(); break;
            case 2:status(); break;
            case 3:pop(); break;
            case 4:peek(); break;
        }
    } while (ch!=0);
}