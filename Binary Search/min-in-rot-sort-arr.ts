
function findMin(nums: number[]): number {
  let l = 0, r = nums.length - 1;
  if (nums[l] < nums[r]) {
    return nums[l];
  }
  while (l < r) {
    const mid: number = Math.floor(l + (r - l) / 2);
    if (nums[mid] >= nums[0]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return nums[r];
};

