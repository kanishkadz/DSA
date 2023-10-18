#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *prv;
    struct Node *next;
};
typedef struct Node N;
N *start = NULL, *ptr, *tmp;

void CreateNode()
{
    ptr = (N*)malloc(sizeof(N));
    printf("\nEnter value:");
    scanf("%d", &ptr->val);
    if (start == NULL)
    {
        start = ptr;
        ptr->prv = ptr;
        ptr->next = ptr;
        tmp = ptr;
    }
    else
    {
        tmp->next = ptr;
        ptr->prv = tmp;
        ptr->next = start;
        start->prv = ptr;
        tmp = ptr;
    }
}

void Print()
{
    if (start == NULL)
    {
        printf("\nEmpty List");
        return;
    }
    else
    {
        N *current = start;
        do
        {
            printf("%d-> ", current->val);
            current = current->next;
        } while (current != start);

        current = current->prv;
        do
        {
            printf("%d<-", current->val);
            current = current->prv;
        } while (current != start->prv);
    }
}

int main()
{
    int ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Insert Value");
        printf("\n2 --> Print");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:CreateNode();break;
        case 2:Print();break;
        }
    } while (ch != 0);
    return 0;
}
