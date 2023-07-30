#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int s, int e)
{
  // considering first element to be pivot
  int pivot = arr[s];
  // counting number of elements which are less than or equall to pivot
  int count = 0;
  for (int i = s + 1; i <= e; i++)
    if (arr[i] <= pivot)
      count++;
  // putting the pivot at its right place
  int pivotIndex = s + count; // correct index for pivot to be at
  swap(arr[pivotIndex], arr[s]);
  /*
   *Now using two pointers to swap
   * elements < p to its left
   * elements > p to its right
   */
  //
  int i = s, j = e;
  while (i < pivotIndex && j > pivotIndex)
  {

    // jabtak left part mein pivot se chote elements pade hue hai tabtak i++ karte jao
    while (arr[i] <= pivot)
      i++;
    // jabtak right part mein pivot se bade elements pade hue hai tabtak j-- karte jao
    while (arr[j] > pivot)
      j--;

    if (i < pivotIndex && j > pivotIndex)
      swap(arr[i++], arr[j--]);
  }
  return pivotIndex;
}
void quickSort(vector<int> &arr, int s, int e)
{
  // Base Case
  if (s >= e)
    return;
  int p = partition(arr, s, e);
  quickSort(arr, s, p - 1);
  quickSort(arr, p + 1, e);
}
int main()
{
  vector<int> arr = {2, 9, 5, 4, 3, 299, 87, 66, 4, 66, 6, 5, 7, 8, 44, 345, 9};
  quickSort(arr, 0, arr.size() - 1);
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << ' ';
  }
  return 0;
}