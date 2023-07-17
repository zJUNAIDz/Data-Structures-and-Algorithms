// https://www.w3resource.com/javascript-exercises/javascript-function-exercise-5.php

const test = "the quick brown fox jumps over lazy dog";
const capitalizeFirstLetter = (str) =>{
let arr = str.split(' ');
for(let i=0;i<arr.length;i++) arr[i].charAt(0).toUpperCase();
return arr.join(' ');
}
console.log(capitalizeFirstLetter(test));