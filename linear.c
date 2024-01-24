#include <stdio.h>
int main() 
{
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == key) 
        {
            printf("Element %d found at index %d.\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) 
    {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}
