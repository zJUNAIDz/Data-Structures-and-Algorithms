// #include <iostream>
// #include <vector>
// using namespace std;

// int findDuplicate(vector<int> &arr)
// {
//     for(int i = 0; i < arr.size();i++){
//         arr = arr && arr[i];
//         if(arr.size()==1) return arr[0];
//     }
//     return 0;
// }

// int main()
// {
//   cout findDuplicate({1,2,3,4,5,6,6,7});
//   return 0;
// }

// #include <iostream>
// #include <unordered_set>
// #include <vector>

// int findDuplicate(const std::vector<int>& arr) {
//     std::unordered_set<int> visited;
//     for (int num : arr) {
//         if (visited.find(num) != visited.end()) {
//             return num;
//         }
//         visited.insert(num);
//     }
//     return -1;
// }

// int main() {
//     std::vector<int> arr = {1, 2, 3, 4, 4, 5};
//     int duplicate = findDuplicate(arr);
//     if (duplicate != -1) {
//         std::cout << "Duplicate element: " << duplicate << std::endl;
//     } else {
//         std::cout << "No duplicate element found." << std::endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(const std::vector<int> &arr)
{
  int n = arr.size();
  int duplicate = 0;

  // Find XOR of all elements from 1 to n-1
  for (int i = 1; i < n; i++)
  {
    duplicate ^= i;
    cout << "duplicate : " << duplicate << " i: " << i << endl;
  }

  // Find XOR of all elements in the array
  for (int num : arr)
  {
    duplicate ^= num;
    cout << "duplicate2 : " << duplicate  << endl;
    
  }

  return duplicate;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 4, 5};
  int duplicate = findDuplicate(arr);
  cout << "Duplicate element: " << duplicate << endl;

  return 0;
}
