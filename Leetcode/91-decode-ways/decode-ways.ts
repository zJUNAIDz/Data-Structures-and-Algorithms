// similar to fibonacci and coin change and word break, optimization from decision tree (2^n) -> memoization -> tabulation 
function numDecodings(s: string): number {
    if (s.length === 0 || s[0] === "0") return 0;
    const dp: number[] = Array(s.length + 1).fill(0);
    
    dp[0] = dp[1] = 1;
    for (let i = 2; i <= s.length; i++) {
        const oneDigit: number = parseInt(s[i - 1]); // previous one digit
        const twoDigits: number = parseInt(s[i - 2] + s[i - 1]); // previous two digits

        if (oneDigit >= 1 && oneDigit <= 9) { 
            dp[i] += dp[i - 1];
        }
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.length]
};
