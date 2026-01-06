// similar to fibonacci and coin change and word break, optimization from decision tree (2^n) -> memoization -> tabulation -> space optimization (using only teo previous values)
function numDecodings(s: string): number {
    if (s.length === 0 || s[0] === "0") return 0;
    let prev1 = 1, prev2 = 1; 
    for (let i = 2; i <= s.length; i++) {
        let curr: number = 0;
        const oneDigit: number = parseInt(s[i - 1]);
        const twoDigits: number = parseInt(s[i - 2] + s[i - 1]);

        if (oneDigit >= 1 && oneDigit <= 9) {
            curr += prev1;
        }
        if (twoDigits >= 10 && twoDigits <= 26) {
            curr += prev2;
        }
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
};
