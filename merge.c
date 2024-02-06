//merge sort
#include<stdio.h>

void printArr(int arr[],int size)
{
	int i;
	for(i=0;i<=size;i++)
    {
		printf("%d  ",arr[i]);
	}
	printf("\n");
}

void merge(int arr[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,k;
	int temp[5];
	while(i<=mid && j<=end)
    {
		if(arr[i]<arr[j])
        {
			temp[index++]=arr[i++];
		}
        else
        {
			temp[index++]=arr[j++];
		}
	}
	while(i<=mid)
    {
		temp[index++]=arr[i++];
	}
	while(j<=end)
    {
		temp[index++]=arr[j++];
	}
	for(k=beg;k<index;k++)
    {
		arr[k]=temp[k];
	}
}

void mergeSort(int arr[],int beg,int end)
{
	int mid;
	if(beg<end)
    {
		mid=(beg+end)/2;
		mergeSort(arr,beg,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,beg,mid,end);	
	}
}

int main()
{
	int i;
	int arr[]={2,1,4,5,3};
	printf("array before sorting : ");
	for(i=0;i<5;i++)
    {
		printf("%d  ",arr[i]);
	}
	printf("\n");
	mergeSort(arr,0,4);
	for(i=0;i<5;i++)
    {
		printf("%d  ",arr[i]);
	}
}