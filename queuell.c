#include<stdio.h>
#include<malloc.h>
struct Queue
{
    int val;
    struct Queue *next;
};
typedef struct Queue Q;
Q *front=NULL, *rear=NULL, *ptr;

void CreateList()
{
    ptr=(Q*)malloc(sizeof(Q));
    printf("\nEnter value to insert:");
    scanf("%d",&ptr->val);
    ptr->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
    }
}
