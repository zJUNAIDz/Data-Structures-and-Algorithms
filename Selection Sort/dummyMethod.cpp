#include <iostream>
#include "print-array.h"
using namespace std;
// DUMMY TRY

int main()
{
    int arr[] = {23, 45, 21, 67, 54, 98, 54, 45, 21};
    int round = sizeof(arr) / sizeof(arr[0]) - 1;
    // cout << round;
    for (int i = 0; i < round - 1; i++)
        for (int j = i + 1; j <= round - 1; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
    printIntArray(arr);
}

// BHIYYA'S METHOD WAS ALSO SAME