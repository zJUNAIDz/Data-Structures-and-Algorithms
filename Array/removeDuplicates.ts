// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

function removeDuplicates(nums: number[]): number[] {
  let i = 0;
  while(i<nums.length){
    if(nums[i] === nums[i+1]){
      nums.splice(i,1);
      continue;
    }
      i++;
  }
  return nums;
}
console.log(removeDuplicates([1,2,3,4,5,5,6,7,8,8,9]));
console.log(removeDuplicates([1,1,2]));
