// Patience Sorting using Binary Search (crazy)
function lengthOfLIS(nums: number[]): number {
    const lis: number[] = [];
    for (let i: number = 0; i < nums.length; i++) {
        const idx: number = leftMostIdx(lis, nums[i]);
        if (idx == nums.length) {
            lis.push(nums[i]); // add new value to the pile if all values are less than current num
        } else {
            lis[idx] = nums[i]; // replace greater value with current 
        }
    }
    return lis.length;

};
function leftMostIdx(arr: number[], target: number): number { // finds leftmost idx in array(of piles) whose value is >= target or else return length of arr.
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
