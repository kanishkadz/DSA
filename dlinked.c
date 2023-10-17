//Doubly Linked List
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
void CreateNode();
void PrintNode();
void InsertFirst();
void InsertLast();
void InsertAfter();
void InsertBefore();
void DeleteFirst();
void DeleteLast();
void DeleteAfter();
void DeleteBefore();
void DeleteNode();

void CreateNode()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter Value:");
    scanf("%d",&ptr->val);
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
        ptr->prv=NULL;
        tmp=ptr;
    }
    else
    {
        tmp->next=ptr;
        ptr->prv=tmp;
        tmp=ptr;
    }
}

void PrintNode()
{
    ptr=start;
    while(ptr->next!=NULL)
    {
        printf("%d-> ",ptr->val);
        ptr=ptr->next;
    }
    while(ptr!=NULL)
    {
        printf("%d <-",ptr->val);
        ptr=ptr->prv;
    }
}

void InsertFirst()
{
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter value to insert:");
    scanf("%d",&ptr->val);
    ptr->next=start;
    ptr->prv=NULL;
    start->prv=ptr;
    start=ptr;
}

void InsertLast()
{
    tmp=start;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    ptr=(N*)malloc(sizeof(N));
    printf("\nEnter value to insert:");
    scanf("%d",&ptr->val);
    ptr->prv=NULL;
    tmp->next=ptr;
}

void InsertAfter()
 {
    int val;
    printf("\nEnter the value after which to insert:");
    scanf("%d", &val);
    tmp = start;
    while (tmp != NULL && tmp->val != val)
    {
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        printf("Value not found in the linked list.\n");
        return;
    }
    N *ptr = (N*)malloc(sizeof(N));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the value:");
    scanf("%d", &ptr->val);
    ptr->prv = tmp;
    ptr->next = tmp->next;
    if (tmp->next != NULL) {
        tmp->next->prv = ptr;
    }
    tmp->next = ptr;
}

void InsertBefore() 
{
    int val;
    printf("\nEnter the value before which to insert:");
    scanf("%d", &val);
    tmp = start;
    if (tmp != NULL && tmp->val == val)
    {
        N *ptr = (N*)malloc(sizeof(N));
        if (ptr == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter a value:");
        scanf("%d", &ptr->val);
        ptr->prv = NULL; 
        ptr->next = tmp; 
        tmp->prv = ptr;   
        start = ptr;      
        return;
    }
    while (tmp != NULL && tmp->next != NULL && tmp->next->val != val)
    {
        tmp = tmp->next;
    }

    if (tmp == NULL || tmp->next == NULL) {
        printf("Value not found in the linked list.\n");
        return;
    }
    N *ptr = (N*)malloc(sizeof(N));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter a value:");
    scanf("%d", &ptr->val);
    ptr->prv = tmp;
    ptr->next = tmp->next;
    tmp->next->prv = ptr;
    tmp->next = ptr;
}

void DeleteFirst()
{
    tmp=start;
    ptr=tmp->next;
    ptr->prv=NULL;
    start=ptr;
    free(tmp);
}

void DeleteLast() 
{
    if (start == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    tmp = start;
    if (tmp->next == NULL) {
        free(tmp);
        start = NULL;
    } 
    else 
    {
        while (tmp->next != NULL) 
        {
            tmp = tmp->next;
        }
        tmp->prv->next = NULL;
        free(tmp);
    }
}


void DeleteAfter()
{
    int val;
    printf("\nEnter the value after which to delete: ");
    scanf("%d", &val);
    if (start == NULL) 
    {
        printf("The linked list is empty.\n");
        return;
    }
    struct Node *tmp = start;
    struct Node *ptr = NULL;
    while (tmp != NULL && tmp->val != val) 
    {
        tmp = tmp->next;
    }
    if (tmp == NULL || tmp->next == NULL) 
    {
        printf("Value not found or no node to delete after.\n");
        return;
    }
    ptr = tmp->next;
    tmp->next = ptr->next;
    free(ptr);
    printf("Node after value %d has been deleted.\n", val);
}


void DeleteBefore()
{
    int val;
    printf("\nEnter the value before which to delete: ");
    scanf("%d", &val);
    if (start == NULL || start->next == NULL) 
    {
        printf("The linked list is empty or has only one node, cannot delete before.\n");
        return;
    }
    struct Node *tmp = start;
    struct Node *ptr = NULL;
    while (tmp != NULL && tmp->val != val) 
    {
        tmp = tmp->next;
    }
    if (tmp == NULL || tmp == start) 
    {
        printf("Value not found or no node to delete before.\n");
        return;
    }
    ptr = tmp->prv;
    ptr->next = tmp;
    tmp->prv = ptr;
    free(ptr);
    printf("Node before value %d has been deleted.\n", val);
}


void DeleteNode()
{
    int n, c = 0, f = 0;
    printf("\nEnter node number: ");
    scanf("%d", &n);
    if (start == NULL) 
    {
        printf("The linked list is empty. Cannot delete a node.\n");
        return;
    }

    struct Node *ptr = start;
    struct Node *tmp = NULL;
    if (n == 1) {
        start = start->next;
        if (start != NULL) 
        {
            start->prv = NULL;
        }
        free(ptr);
        printf("Node 1 has been deleted.\n");
        return;
    }
    while (ptr != NULL) 
    {
        c++;
        if (c == n) {
            f = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (f == 1) 
    {
        tmp = ptr;
        ptr->prv->next = tmp->next;
        if (tmp->next != NULL) 
        {
            tmp->next->prv = ptr;
        }
        free(tmp);
        printf("Node %d has been deleted.\n", n);
    } 
    else 
    {
        printf("Node not found.\n");
    }
}


void main()
{
    int ch;
    do
    {
        printf("\n -: M E N U :-");
        printf("\n1 --> Create node");
        printf("\n2 --> Print node");
        printf("\n3 --> Insert a node at first");
        printf("\n4 --> Insert a node at last");
        printf("\n5 --> Insert after a node");
        printf("\n6 --> Insert before a node");
        printf("\n7 --> Delete first node");
        printf("\n8 --> Delete last node");
        printf("\n9 --> Delete after a node");
        printf("\n10 --> Delete before a node");
        printf("\n11 --> Delete any node");
        printf("\n0 --> Exit");
        printf("\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: CreateNode(); break;
            case 2: PrintNode(); break;
            case 3: InsertFirst(); break;
            case 4: InsertLast(); break;
            case 5: InsertAfter(); break;
            case 6: InsertBefore(); break;
            case 7: DeleteFirst(); break;
            case 8: DeleteLast(); break;
            case 9: DeleteAfter(); break;
            case 10: DeleteBefore(); break;
            case 11: DeleteNode(); break;
        }
    } while (ch!=0);
    
}