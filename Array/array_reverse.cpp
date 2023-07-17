#include <iostream>
#include <array>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int len = sizeof(arr)/sizeof(arr[0])-1;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0])-1 ; i++)
    {
        if (i < len)
        {
            swap(arr[i], arr[len]);
            len --;
        }
    }
    for (int i = 0; i < 8 ;i++)
        cout << arr[i] << " ";
}