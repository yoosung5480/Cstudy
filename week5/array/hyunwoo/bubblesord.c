#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int* arr, int n)
{
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(&arr[i], &arr[i+1]);
            }
        }
    }
}

int main()
{   
    int arr[] = {5,4,2,1,4};
    sort(arr, sizeof(arr)/sizeof(int));

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}