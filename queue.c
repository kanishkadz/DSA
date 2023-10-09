#include<stdio.h>
#define size 5
int Q[size];
int front =-1;
int rear =-1;
void Insert();
void Status();
void Delete();

void Insert()
{
    int n;
    if(front>rear)
    {
        printf("\nQueue Underflow");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=rear-1;
    }
    printf("\nEnter value to insert:");
    scanf("%d",&n);
    Q[rear]=n;
}

void Status()
{
    int i;
    if(front==-1 && rear==-1 || front>rear)
    {
        printf("\nQueue Underflow");
        return;
    }
    printf("\nQueue is now:");
    for(i=front;i<=rear;i++)
    {
        printf("\n%d",Q[i]);
    }
}

void Delete()
{
    if(front>rear)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        front=front+1;
    }
}

void main()
{
    int ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Insert");
        printf("\n2 --> Status");
        printf("\n3 --> Delete");
        printf("\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: Insert(); break;
            case 2: Status(); break;
            case 3: Delete(); break;
        }
    } while (ch!=0);   
}