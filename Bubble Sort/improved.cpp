#include <iostream>
using namespace std;
void bubblify(int *arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len - 1 - i; j++)
    {
      for (int k = 0; k < len; k++)
        cout << arr[k] << " ";
      cout << endl;
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
  for (int i = 0; i < len; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
  int arr[] = {4, 3, 2, 1, 5, 4, 77, 65, 45, 34, 33, 56, 43, 4, 0};
  bubblify(arr, 15);
  return 0;
}