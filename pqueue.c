#include<stdio.h>
#define size 5
void InsertPQ(int);
void DeletePQ(int);
void Check(int);
void DisplayPQ();

int PQ[size];
int front=-1, rear=-1;

void main()
{
    int n,ch;
    do
    {
        printf("\n-: M E N U :-");
        printf("\n1 --> Insert");
        printf("\n2 --> Delete");
        printf("\n3 --> Display");
        printf("\n4 --> Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter value to insert:");
                    scanf("%d",&n);
                    InsertPQ(n); break;
            case 2: printf("\nEnter value to delete:");
                    scanf("%d",&n);
                    DeletePQ();
                    break;
            case 3: DisplayPQ(); break;
        }
    } while (ch!=4);
}
