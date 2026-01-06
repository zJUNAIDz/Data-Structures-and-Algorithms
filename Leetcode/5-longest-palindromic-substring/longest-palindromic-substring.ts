function longestPalindrome(s: string): string {
    let ans: string = "";
    let longestLen: number = 0;
    // for odds
    for (let i = 0; i < s.length; i++) {
        const res = findLongest(i, i, s);
        if (longestLen < res.length) {
            longestLen = res.length;
            ans = res;
        }
    }
    // for evens
    for (let i = 0; i < s.length - 1; i++) {
        const res = findLongest(i, i + 1, s)
        if (longestLen < res.length) {
            longestLen = res.length;
            ans = res;
        }
    }
    return ans;
};

function findLongest(i: number, j: number, str: string): string {
    let left = i, right = j;
    while (left >= 0 && right < str.length && str[left] === str[right]) {
        left--;
        right++;
    }
    return str.substring(left + 1, right)
}
