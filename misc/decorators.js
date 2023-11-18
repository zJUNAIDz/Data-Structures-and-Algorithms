//NOTE:  The Flabbergasting conclusion to this experiment caused me severe emotional damage, factorial fuction is faster than cached one.

//* Heavy compution fuction (must be pure)
const factorial = (x) => (x <= 1 ? 1 : x * factorial(x - 1));

function cachingDecorator(factorial) {
  let cache = new Map();
  return function (x) {
    if (cache.has(x)) {
      console.log("Already in Cache...");
      return cache.get(x);
    }
    console.log("Caching...");
    const result = factorial(x);
    cache.set(x, result);
    return result;
  };
}

const cachedFactorial = cachingDecorator(factorial);
//*performance Check (disappointing) maybe decorator is slowing it down due to extra Map gymnastics and +1 function call 
// let start = performance.now();
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(2));
// console.log(cachedFactorial(3));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// console.log(cachedFactorial(100));
// let end = performance.now();
// console.log(end - start + " ms");

// start = performance.now();

// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));
// console.log(factorial(100));

// end = performance.now();
// console.log(end - start + " ms");
