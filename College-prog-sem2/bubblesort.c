#include<stdio.h>

void swap();

void main(){
    int l;
    printf("Enter the length of the array \n");
    scanf("%d", &l);
    int arr[l];
    printf("Enter the elements in the array \n");
    for(int i = 0; i < l; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l-i; j++)
        {
            if(arr[j] >arr[j+1]){
                swap(arr,j,j+1);
            }
        }
        
    }
    printf("Sorted array is: \n");
    for (int i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
    
    
}

void swap(int arr[], int first,int second){
    int temp =0;
    temp = arr[first];
    arr[first]= arr[second];
    arr[second]=temp;
    return;
}