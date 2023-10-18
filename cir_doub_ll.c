#include<stdio.h>
#include<malloc.h>
struct Node
{
    int val;
    struct Node *prv;
    struct Node *next;
};
typedef struct Node N;
N *start=NULL, *ptr, *tmp;

void CreateNode()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter value:");
    scanf("%d",&ptr->val);
    if(start==NULL)
    {
        start=ptr;
        ptr->prv=ptr;
        ptr->next=ptr;
        tmp=ptr;
    }
    else
    {
        tmp->next=ptr;
        ptr->prv=tmp;
        ptr->next=start;
        start->prv=ptr;
        tmp=ptr;
    }
}

void Print()
{
    if(start==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    else
    {
        while(ptr->next!=start)
        {
            printf("%d-> ",ptr->val);
            ptr=ptr->next;
        }
        while(ptr!=start)
        {
            printf(" %d<-",ptr->val);
            ptr=ptr->prv;
        }
    }

}