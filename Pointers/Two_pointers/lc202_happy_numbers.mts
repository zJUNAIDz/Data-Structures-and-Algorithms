function getNext(n: number): number {
  let sum = 0;
  while (n > 0) {
    const digit = n % 10;
    sum += digit * digit;
    n = Math.floor(n / 10);
  }
  return sum;
}
function isHappy(n: number): boolean {
  let slow = n;
  let fast = getNext(n);
  while (fast !== 1 && slow !== fast) {
    slow = getNext(slow);
    fast = getNext(getNext(fast));
    console.log({ fast, slow });
  }
  return fast === 1;
}
//Test
console.log(isHappy(2));
