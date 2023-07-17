const solution = (firstArray, secondArray)=> {
    let squaredArray = [], sum = 0;
    for (let i in firstArray){
       let diff =  secondArray[i] - firstArray[i];
       squaredArray.push(diff**2);
     
    } 
    for (let i in squaredArray){
        sum += squaredArray[i];
    }
    console.log(sum);
    //  = 
    return sum/(squaredArray.length);
}
console.log(solution([1,2,3],[4,5,6]));