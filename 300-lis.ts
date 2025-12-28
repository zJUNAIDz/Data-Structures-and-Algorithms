function lengthOfLIS(nums: number[]): number {
  const lis: number[] = [nums[0]];
  let i: number = 0;
  for (let i = 0; i < nums.length; i++) {
    const idx: number = leftMostIdx(lis, nums[i]);
    if (idx == nums.length) {
      lis.push(nums[i]);
    } else {
      lis[idx] = nums[i];
    }
  }
  return lis.length;

};
function leftMostIdx(arr: number[], target: number): number {
  let left: number = 0;
  let right: number = arr.length - 1;
  while (left <= right) {
    const mid: number = Math.floor((left + right) / 2);
    if (arr[mid] >= target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
