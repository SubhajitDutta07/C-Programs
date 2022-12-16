#include <math.h>
#include <stdio.h>
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j > 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j] = key;
    }
}
  
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  
/* Driver program to test insertion sort */
void main()
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
    printf("Before sorting: \n");
    printArray(a, l);
    insertionSort(a, l);
    printf("After sorting: \n");
    printArray(a, l);
  
    return ;
}