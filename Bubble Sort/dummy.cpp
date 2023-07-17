#include <iostream>
using namespace std;

int main()
{
    bool isSwapped = false;
    int arr2[] = {8, 22, 7, 9, 31, 5, 13};
    int arr[] = {23, 45, 65, 87, 43, 56, 42, 98, 11};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < len; i++)
    {
        isSwapped = false;
        for (int j = 0; j < len - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                isSwapped = true;
                swap(arr[j], arr[j + 1]);
                // int temp;
                // temp = arr[i];
                // arr[i] = arr[i + 1];
                // arr[i + 1] = temp;
            }
            else
            {
                isSwapped = false;
            }
        }
        if (!isSwapped)
            break;
    }
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}