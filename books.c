#include<stdio.h>
#include<malloc.h>
struct Node
{
    char n[20];
    int price;
    struct Node *next;
};
typedef struct Node N;
N *start,*n1,*n2,*n3;
void main()
{
    n1=(N*)malloc(sizeof(N));
    start=n1;
    printf("\nEnter Author for book 1:");
    gets(n1->n);
    printf("\nEnter price for book 1:");fflush(stdin);
    scanf("%d",&n1->price);
    n1->next=NULL;
    n2=(N*)malloc(sizeof(N));
    n1->next=n2;
    printf("\nEnter Author for book 2:");
    gets(n2->n);
    printf("\nEnter price for book 2:");fflush(stdin);
    scanf("%d",&n2->price);
    n2->next=NULL;
    n3=(N*)malloc(sizeof(N));
    n2->next=NULL;
    printf("\nEnter Author for book 3:");
    gets(n3->n);
    printf("\nEnter price for book 3:");fflush(stdin);
    scanf("%d",&n3->price);
    n3->next=NULL;
}


