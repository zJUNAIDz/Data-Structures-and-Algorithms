const arr: number[] = [4, 5, 3, 2, 1, 4, 55, 64, 33, 24, 54, 13];
console.log("Original: ", arr);

for (let i = 0; i < arr.length; i++)
  for (let j = 0; j < arr.length - 1 - i; j++)
    if (arr[j] > arr[j + 1]) [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];

console.log("Sorted: ", arr);
