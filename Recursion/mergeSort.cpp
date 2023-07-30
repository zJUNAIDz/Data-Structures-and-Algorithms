#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int s, int e)
{
  int mid = s + (e - s) / 2;
  int len1 = mid - s + 1;
  int len2 = e - mid;

  /*
   *making two arrays(size of actual array / 2) and copying values ofarray into these two arrays
   */

  int *first = new int[len1];
  int *second = new int[len2];

  // copying left part (s to mid) in first array
  int k = s;
  for (int i = 0; i <= len1; i++)
    first[i] = arr[k++];
  // copying left part (s to mid) in first array
  k = mid + 1;
  for (int i = 0; i <= len2; i++)
    second[i] = arr[k++];
  /*
   *Now Merging those two array in a sorted manner.
   TODO: for now, I am gonna use unoptimized approach of "Merge 2 sorted Arrays" problem. It would be great if I change that in future.
   */
  // making two pointers to traverse on each array
  int index1 = 0;
  int index2 = 0;
  // pointer to main array
  k = s;
  // to traverse both array and put smaller one and point to next element of smaller element
  while (index1 < len1 && index2 < len2)
  {
    if (first[index1] < second[index2])
    {
      arr[k++] = first[index1++];
    }
    else
    {
      arr[k++] = second[index2++];
    }
  }
  /*
   *Just in case if number of elements in both aren't same
   * In this case, bigger element will only be bigger by 1 element
   * but still we are gonna use generalized approach for a meantime.
   */
  // if elements of left array are left(remaining)
  while (index1 < len1)
  {
    arr[k++] = first[index1++];
  }
  while (index2 < len2)
  {
    arr[k++] = second[index2++];
  }
  delete[] first;
  delete[] second;
}
void mergeSort(vector<int> &arr, int s, int e)
{
  /*
   *Remember to put '>=' sign because when s=e, it points to same single element
   *As we know single element is always considered to be sorted.
   *putting only '>' sign will give an infinite loop
   */
  if (s >= e)
    return;
  cout << "Hi" << endl;
  int mid = s + (e - s) / 2;
  // Left side ke tukde kardo
  mergeSort(arr, s, mid);

  // Right part ke tukde kardo
  mergeSort(arr, mid + 1, e);

  // ab merge karo mast sorted mafik
  merge(arr, s, e);
}
int main()
{
  vector<int> arr = {2, 9, 5, 4, 3, 299, 87, 66, 4, 66, 6, 5, 7, 8, 44, 345, 9};
  mergeSort(arr, 0, arr.size() - 1);
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << ' ';
  }

  return 0;
}