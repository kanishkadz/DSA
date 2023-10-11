#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node N;
N *start = NULL, *ptr, *tmp;
void CreateList();
void PrintList();

void main() 
{
    int ch;
    do 
    {
        printf("\n-: M E N U:-");
        printf("\n1 --> Create List");
        printf("\n2 --> Print List");
        printf("\n0 --> Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch) 
        {
            case 1: CreateList(); break;
            case 2: PrintList(); break;
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
