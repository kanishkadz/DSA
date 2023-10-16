#include <stdio.h>
#define size 5

void InsertPQ(int);
void DeletePQ(int);
void DisplayPQ();
void Check(int);

int PQ[size];
int front = -1, rear = -1;

int main() 
{
    int n, ch;
    do 
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Insert");
        printf("\n2 --> Delete");
        printf("\n3 --> Display");
        printf("\n4 --> Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("\nEnter value to insert:");
                scanf("%d", &n);
                InsertPQ(n);
                break;
            case 2:
                printf("\nEnter value to delete:");
                scanf("%d", &n);
                DeletePQ(n);
                break;
            case 3:
                DisplayPQ();
                break;
        }
    } while (ch != 4);
    return 0;
}

void InsertPQ(int data) 
{
    if (rear >= size - 1) 
    {
        printf("\nQueue Overflow");
        return;
    }
    if (front == -1 && rear == -1) {

        front = 0;
        rear = 0;
        PQ[rear] = data;
    } 
    else 
    {
        Check(data);
    }
    rear++;
}

void Check(int data) 
{
    int i, j;
    for (i = 0; i <= rear; i++) 
    {
        if (data >= PQ[i]) {
            for (j = rear; j > i; j--) 
            {
                PQ[j] = PQ[j - 1];
            }
            PQ[i] = data;
            return;
        }
    }
    PQ[i] = data;
}

void DeletePQ(int data) 
{
    int i;
    if (front == -1 && rear == -1) 
    {
        printf("\nQueue is empty");
        return;
    }
    for (i = 0; i <= rear; i++)
    {
        if (data == PQ[i]) 
        {
            for (; i < rear; i++) 
            {
                PQ[i] = PQ[i + 1];
            }
            rear--;
            if (front > rear) 
            {
                front = rear = -1;
            }
            return;
        }
    }
    printf("%d not found", data);
}

void DisplayPQ() 
{
    if (front == -1 && rear == -1) 
    {
        printf("\nQueue is empty");
        return;
    }
    for (int i = front; i <= rear; i++) 
    {
        printf(" %d ", PQ[i]);
    }
}
