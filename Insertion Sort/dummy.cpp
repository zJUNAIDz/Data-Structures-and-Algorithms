#include <iostream>
using namespace std;

int main()
{
    int arr[] = {87, 34, 53, 16, 88, 23, 45, 63, 12, 32, 11};
    int holder;
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        cout << " iteration = " << i << endl
             << endl;
        holder = arr[i];
        cout << "arr[i] =" << arr[i] << endl;
        cout << "holder =" << holder << endl;
        for (int j = i + 1; j < len; j++)
        {
            cout << "Arr[j] =" << arr[j] << endl;
            if (arr[j] < arr[i])
            {
                holder = arr[j];
                swap(arr[j], holder);
                break;
                cout << "holder = " << holder << endl;
            }
        }
    }
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
}