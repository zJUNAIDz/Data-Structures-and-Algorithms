#include <iostream>
using namespace std;
int findPivot(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
            start = mid + 1;
        else
            end = mid;

        mid = start + (end - start) / 2;
    }
    return start;
}
int main()
{
    int arr[] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of Pivot Element is " << findPivot(arr, arr_size) << endl;
    return 0;
}