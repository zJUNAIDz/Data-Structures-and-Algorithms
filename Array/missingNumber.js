// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&category[]=Arrays&sortBy=submissions

// const missingNumber = (arr, n) => {
//   const sortedArr = arr.sort((a, b) => a - b);
//   for (let i = 0; i < n - 1; i++) {
//     if (sortedArr[i] !== sortedArr[i + 1] + 1) return sortedArr[i] + 1;
//     else continue;
//   }
// };
// console.log(missingNumber([1, 2, 4, 5, 3, 6, 7, 9], 9));

class Solution {
  missingNumber(array, n) {
    //code here
    const sortedArr = array.sort((a, b) => a - b);
    console.log(sortedArr);
    for (let i = 0; i < n - 1; i++) {
      if (sortedArr[i] !== sortedArr[i + 1] - 1) return sortedArr[i] + 1;
      else continue;
    }
  }
}

const obj = new Solution;
console.log(obj.missingNumber([1, 2, 4, 5, 3, 6, 7, 9], 9))