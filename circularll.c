#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node N;
N *start = NULL, *ptr, *tmp, *tmp1;
void CreateList();
void PrintList();
void InsertLast();
void InsertBefore();

void main() 
{
    int ch;
    do 
    {
        printf("\n-: M E N U:-");
        printf("\n1 --> Create List");
        printf("\n2 --> Print List");
        printf("\n3 --> Insert at last");
        printf("\n4 --> Insert before an element");
        printf("\n0 --> Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch) 
        {
            case 1: CreateList(); break;
            case 2: PrintList(); break;
            case 3: InsertLast(); break;
            case 4: InsertBefore(); break;
        }
    }while(ch != 0);
}

void CreateList() 
{
    ptr = (N*)malloc(sizeof(N));
    printf("\nEnter value: ");
    scanf("%d", &ptr->val);
    if (start == NULL) 
    {
        start = ptr;
        tmp = ptr;
        ptr->next = start;
    } 
    else 
    {
        tmp->next = ptr;
        tmp = ptr;
        ptr->next = start;
    }
}

void PrintList() 
{
    if (start == NULL) 
    {
        printf("\nEmpty List");
        return;
    }
    ptr = start;
    do 
    {
        printf("%d -> ", ptr->val);
        ptr = ptr->next;
    } while (ptr != start);
    printf("%d ", ptr->val);
}

void InsertLast()
{
    tmp = start;
    while (tmp->next != start)
    {
        tmp = tmp->next;
    }
    ptr = (N*)malloc(sizeof(N));
    if (ptr == NULL) 
    {
        return;
    }
    ptr->next = start;  
    tmp->next = ptr; 
}

void InsertBefore()
{
    int v;
    tmp=start;
    printf("\nEnter the value before which to insert:");
    scanf("%d",&v);
    while(tmp->val!=v)
    {
        tmp1=tmp;
        tmp=tmp->next;
    }
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter a value:");
    scanf("%d",&ptr->val);
    tmp->next=ptr;
    ptr->next=tmp;
}