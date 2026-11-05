#include <stdio.h>
int binarySearch(int arr[], int, int, int);
void bubbleSort(int arr[], int n);
int main()
{
    int n, target, result;
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\n Enter %d integers (in any order):", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("\n The auto-arranged (sorted) array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n Enter the element to search for: ");
    scanf("%d", &target);
    result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
    {
        printf("\n Element %d is not present in the array.", target);
    }
    else
    {
        printf("\n Element %d found at index %d.", target, result);
    }
    return 0;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
