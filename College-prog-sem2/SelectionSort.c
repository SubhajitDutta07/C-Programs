#include <stdio.h>  
  
void selection(int arr[], int n)  
{  
    int i, j, small;  
      
    for (i = 0; i < n-1; i++)    // One by one move boundary of unsorted subarray  
    {  
        small = i; //minimum element in unsorted array  
          
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[small])  
            small = j;  
// Swap the minimum element with the first element  
    int temp = arr[small];  
    arr[small] = arr[i];  
    arr[i] = temp;  
    }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  
int main()  
{   
    printf("Enter the length of the array:\n");
    int l=0 ;
    scanf("%d",&l);
    int a[l];
    printf("Enter the elements in the array: \n");
    for (int i = 0; i < l; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Before sorting array elements are - \n");  
    printArr(a, l);  
    selection(a, l);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, l);  
    return 0;  
}    