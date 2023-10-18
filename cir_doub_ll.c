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

void main()
{
    int ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Insert Value");
        printf("\n2 --> Print");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: CreateNode(); break;
            case 2: Print(); break;
        }
    } while (ch!=0);
    
}