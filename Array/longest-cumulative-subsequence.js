function LongestConsecutive(arr) {
    // code goes here
    const hashSet = new Set(arr);
    let longest = 0;
    for (let num of hashSet) {
        if (!hashSet.has(num - 1)) {
            //this should be start of sequence
            let curr = num;
            let count = 1;
            while (hashSet.has(curr + 1)) {
                curr++;
                count++;
            }
            longest = Math.max(longest, count);
        }
    }
    return longest;
}
console.log(LongestConsecutive([100, 4, 200, 1, 3, 2]));
