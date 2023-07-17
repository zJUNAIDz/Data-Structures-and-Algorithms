#include <iostream>
using namespace std;

int bSearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;
    int mid = start + (end - start) / 2;
    // int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid] )
            start = mid + 1;
        else if (key < arr[ mid ])
            end = mid - 1;
         mid = start + (end - start) / 2;
    }
        return 0;
}

int main()
{
    int arr[] = {1, 2, 4, 5, 7, 8, 9, 10};
    int key = 9;
    cout << bSearch(arr, 12, key);
    return 0;
}