#include<stdio.h>
#define size 5
void InsertPQ(int);
void DeletePQ(int);
void Check(int);
void DisplayPQ();

int PQ[size];
int front=-1, rear=-1;

void main()
{
    int n,ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Insert");
        printf("\n2 --> Delete");
        printf("\n3 --> Display");
        printf("\n4 --> Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter value to insert:");
                    scanf("%d",&n);
                    InsertPQ(n); break;
            case 2: printf("\nEnter value to delete:");
                    scanf("%d",&n);
                    DeletePQ(n);
                    break;
            case 3: DisplayPQ(); break;
        }
    } while (ch!=4);
}

void InsertPQ(int data)
{
    if(rear>=size-1)
    {
        printf("\nQueue Overflow");
        return;
    }
    if((front==-1) &&(rear==-1))
    {
        front++;
        rear++;
        PQ[rear]=data;
        return;
    }
    else
    {
        Check(data);
    }
    rear++;
}

void Check(int data)
{
    int i,j;
    for(i=0;i<=rear;i++)
    {
        if(data>=PQ[i])
        {
            for(j=rear+1;j>1;j--)
            {
                PQ[j]=PQ[j-1];
                PQ[i]=data;
                return;
            }
        }
        PQ[i]=data;
    }
}

void DeletePQ(int data)
{
    int i;
    if((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty");
        return;
    }
    for(i=0;i<=rear;i++)
    {
        if(data==PQ[i])
        {
            for(;i<rear;i++)
            {
                PQ[i]=PQ[i+1];
            }
            rear--;
            if(front==-1)
            {
                front=-1;
                return;
            }
            printf("%d not found",data);
        }
    }
}

void DisplayPQ()
{
    if((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty");
        return;
    }
    for(;front<=rear;front++)
    {
        printf(" %d ",PQ[front]);
    }
    front=0;
}