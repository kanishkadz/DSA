#include <stdio.h>
int main() 
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';
    int totalMoves = 0;
    for (int i = 1; i < (1 << n); i++) 
    {
        int fromPeg = (i & i - 1) % 3 + 1;
        int toPeg = ((i | i - 1) + 1) % 3 + 1;
        printf("Move disk from Peg %d to Peg %d\n", fromPeg, toPeg);
        totalMoves++;
    }
    printf("\nTotal number of moves: %d\n", totalMoves);
    return 0;
}
