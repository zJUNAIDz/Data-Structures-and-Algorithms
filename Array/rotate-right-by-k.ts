// 189. Rotate Array

function rotate(nums: number[], k: number): void {
  const n = nums.length;
  const kk = k % n;
  //* store elements from n-kk to n
  const temp: number[] = [];
  for (let i = n - kk; i < n; i++) {
    temp.push(nums[i]);
  }
  console.log({ temp });

  //move the elements from 0 to kk
  for (let i = n - kk - 1; i >= 0; i--) {
    nums[i + kk] = nums[i];
  }
  console.log({ afterMove: nums });

  //attach temp

  for (let i = 0; i < temp.length; i++) {
    nums[i] = temp[i];
  }
  console.log({ final: nums });
}
rotate([-1, -100, 3, 99], 2);
