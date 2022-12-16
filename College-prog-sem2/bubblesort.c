#include<stdio.h>

void swap();
void display();

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

    printf("Array before sorting \n");
    display(arr,l);

    for (int i = 0; i < l; i++)
    {
        int flag = 0;
        for (int j = 0; j < l-i; j++)
        {
            if(arr[j] >arr[j+1]){
                swap(arr,j,j+1);
                flag =1;
            }
        }
        if(flag == 0){
            break;
        }    
    }
    printf("Sorted array is: \n");
    display(arr,l);
    
}

void swap(int arr[], int first,int second){
    int temp =0;
    temp = arr[first];
    arr[first]= arr[second];
    arr[second]=temp;
    return;
}

void display(int arr[],int l){
    for (int i = 0; i < l; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}