#include<stdio.h>
#define size 5
int stack[size];
int top=-1;
void push();
void pop();
void peep();
void status();

void push()
{
    int n;
    if(top==size-1)
    {
        printf("\nStack Overflow");
        return;
    }
    printf("\nEnter value to push:");
    scanf("%d",&n);
    top=top+1;
    stack[top]=n;
}

void status()
{
    int i;
    if(top==-1)
    {
        printf("\nStack Underflow");
        return;
    }
    printf("Stack is now:");
    for(i=top;i>=0;i--)
    {
        printf("\n%d",stack[i]);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow");
        return;
    }
    printf("\n%d is popped",stack[top]);
    top=top-1;
}

void peek()
{
    if(top==-1)
    {
        printf("\nStack Underflow");
        return;
    }
    printf("\nTop value is %d",stack[top]);
}

void main()
{
    int ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Push");
        printf("\n2 --> Status");
        printf("\n3--> Pop");
        printf("\n4 --> Peek");
        printf("\n0 --> Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(); break;
            case 2: status(); break;
            case 3: pop(); break;
            case 4: peek(); break;
        }
    } while (ch!=0);
}
