#include <iostream>
using namespace std;

int focc(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
            {
                ans = mid;
                end = mid -1;
            }
        else if (key > arr[mid] )
            start = mid + 1;
        else if (key < arr[ mid ])
            end = mid - 1;
         mid = start + (end - start) / 2;
    }
        return ans;
}

int locc(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
            {
                ans = mid;
                start = mid +1;
            }
        else if (key > arr[mid] )
            start = mid + 1;
        else if (key < arr[ mid ])
            end = mid - 1;
         mid = start + (end - start) / 2;
    }
        return ans;
}

int main()
{
    int arr[] = {1, 2, 4, 5, 7,9, 9, 9, 10};
    int key = 9;
    int arr_size = sizeof(arr)/sizeof(arr[0])-1;
    cout << focc(arr, arr_size, key)<<endl;
    cout << locc(arr, arr_size, key)<<endl;
    cout << locc(arr, arr_size, key)- focc(arr, arr_size, key) +1 <<endl;
    return 0;
}