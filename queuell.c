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

void StatusQ()
{
    ptr=front;
    printf("\nQueue is now:-\n");
    while(ptr!=NULL)
    {
        printf("%d",ptr->val);
        ptr=ptr->next;
    }
}

void DeleteQ()
{
    ptr=front;
    if(front==NULL)
    {
        printf("\nQueue Overflow");
        return;
    }
    printf("\n%d is deleted",front->val);
    front=front->next;
    free(ptr);
}
