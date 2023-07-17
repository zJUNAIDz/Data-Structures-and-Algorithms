// // https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// const sort = (arr,l,r) => {
//   for (let i = l; i < r+1; i++) {
//     for (let j = i + 1; j < r+1; j++) {
//       if (arr[i] > arr[j]) {
//         let temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//       } else continue;
//     }
//   }
//   return arr;
// };
// const kthSmallest = (arr, l, r, k) => {
// };
// console.log(sort([1,4,5,3,2,78,65,3,22],0,8));
class Solution {
  kthSmallest(arr, l, r, k) {
    //code here
    const sort = (arr, l, r) => {
      for (let i = l; i < r + 1; i++) {
        for (let j = i + 1; j < r + 1; j++) {
          if (arr[i] > arr[j]) {
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
          } else continue;
        }
      }
      return arr;
    };
    let newArr = sort(arr, l, r);
    return newArr[k - 1];
  }
}
