#include<stdio.h>
#define size 5
int CQ[size];
int front=-1;
int rear=-1;
void Insert();
void Status();
void Delete();

void Insert()
{
    int val;
    if((rear==size-1 && front==0)||rear==front-1)
    {
        printf("\nCircular Queue Overflow");
        return;
    }
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==size-1 && front!=0)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
        printf("\nEnter value:");
        scanf("%d",&val);
        CQ[rear]=val;
    }
}

void Status()
{
    int i;
    printf("\nQueue is now:-");
    if(front==-1 && rear==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        i=front;
        while(i!=rear)
        {
            printf("%d",CQ[i]);
            i=(i+1)%size;
        }
        printf(" %d",CQ[rear]);
    }
}

void Delete()
{
    if(front==-1)
    {
        printf("\nQueue Underflow");
        return;
    }
    printf("%d is deleted",CQ[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==size-1)
    {
        front=0;
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
        printf("\n1--> Insert");
        printf("\n2--> Status");
        printf("\n3--> Delete");
        printf("\n0--> Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: Insert(); break;
            case 2: Status(); break;
            case 3: Delete(); break;
        }
    } while (ch!=0);
}