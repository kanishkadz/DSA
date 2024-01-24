#include <stdio.h>
int main() 
{
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int low = 0, high = n - 1, mid, found = 0;
    while (low <= high) 
    {
        mid = (low + high) / 2;
        if (arr[mid] == key) 
        {
            printf("Element %d found at index %d.\n", key, mid);
            found = 1;
            break;
        } 
        else if (arr[mid] < key)
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    if (!found) 
    {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}
