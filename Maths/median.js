// Median of an Unsorted array
function find_median(arr) { 
    let ans = 0;
    let sortedArray = arr.sort((a, b)=> a - b);
    let len = sortedArray.length;
    if(len%2 ===0) ans = (sortedArray[len/2-1]+sortedArray[len/2] )/2;
    else ans = sortedArray[Math.floor(len/2)];
    return Math.floor(ans); 
}
console.log(find_median([90, 100, 78, 89, 67, 45]));