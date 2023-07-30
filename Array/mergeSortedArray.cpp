#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int n)
{
  cout << '[';
  for (int i = 0; i < n; i++)
  {
    if (i == n - 1)
      cout << arr[i];
    else
      cout << arr[i] << ", ";
  }
  cout << ']';
}
void merge(int nums1[], int m, int nums2[], int n, int arr3[])
{
  // two pointer approach lagade bhayyy
  // two pointer variables....
  int i = 0;
  int j = 0;
  int index = 0;
  while (i < n && j < m)
  {
    // couts
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
    cout << "index: " << index << endl;
    if (nums1[i] < nums2[j])
    {
      arr3[index++] = nums1[i++];
    }
    else if (nums1[i] > nums2[j])
    {
      arr3[index++] = nums2[j++];
    }
    else
    {
      arr3[index++] = nums1[i++];
      arr3[index++] = nums2[j++];
    }
  }
  while (i < n)
  {
    arr3[index++] = nums1[i++];
  }
  while (j < m)
  {
    arr3[index++] = nums2[j++];
  }
  print(arr3, 8);
}

int main()
{
  int nums1[] = {1, 3, 5, 7, 9};
  int nums2[] = {2, 4, 6};
  int m = sizeof(nums1) / sizeof(nums1[0]);
  // cout << n << endl;
  int n = sizeof(nums2) / sizeof(nums2[0]);
  cout << m << endl;

  int arr3[9] = {0};
  merge(nums1, m, nums2, n, arr3);
  return 0;
}

// class Solution
// {
// public:
//   void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//   {
//     int i = 0;
//     int j = 0;
//     int index = 0;
//     while (i < n && j < m)
//     {
//       if (nums1[i] < nums2[j])
//         arr3[index++] = nums1[i++];
//       else if (nums1[i] > nums2[j])
//         arr3[index++] = nums2[j++];
//       else
//       {
//         arr3[index++] = nums1[i++];
//         arr3[index++] = nums2[j++];
//       }
//     }
//     while (i < n)
//       arr3[index++] = nums1[i++];
//     while (j < m)
//       arr3[index++] = nums2[j++];
//     nums1 = arr3;
//   }
// };