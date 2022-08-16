#include<stdio.h>

int binarySearch(int arr[], int start, int end, int target)
{
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target
    )
            return mid;
        if (arr[mid] > target
    )
            return binarySearch(arr, start, mid - 1, target
        );
        return binarySearch(arr, mid + 1, end, target
    );
    }
    return -1;
}
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, length - 1, target);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at indetarget
     %d", result);
    return 0;
}