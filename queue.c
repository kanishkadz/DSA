#include <stdio.h>
#define size 5
int Q[size];
int front = -1;
int rear = -1;

void Insert();
void Status();
void Delete();

void Insert() 
{
    int n;
    if (rear == size - 1) 
    {
        printf("\nQueue Overflow");
    } 
    else 
    {
        printf("\nEnter value to insert: ");
        scanf("%d", &n);
        if (front == -1) 
        {
            front = 0;
        }
        rear = rear + 1;
        Q[rear] = n;
    }
}

void Status() 
{
    if (front == -1 || front > rear) 
    {
        printf("\nQueue is empty");
    } 
    else 
    {
        printf("\nQueue is now: ");
        for (int i = front; i <= rear; i++) 
        {
            printf("%d ", Q[i]);
        }
    }
}

void Delete() 
{
    if (front == -1) 
    {
        printf("\nQueue Underflow");
    } 
    else 
    {
        printf("\nDeleted element: %d", Q[front]);
        front = front + 1;
        if (front > rear) 
        {
            front = rear = -1;
        }
    }
}

void main() 
{
    int ch;
    do 
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Insert");
        printf("\n2 --> Status");
        printf("\n3 --> Delete");
        printf("\n0 --> Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1: Insert(); break;
            case 2: Status(); break;
            case 3: Delete(); break;
        }
    } while (ch != 0);
}
