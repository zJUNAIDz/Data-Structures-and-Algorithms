// let arg1 = "foefet", arg2 = "toffee";
// const isAnagram = (arg1, arg2)=>{

//     let arr1 =arg1.split("");
//     let arr2 =arg2.split("");
//     for (let i in arr1){
//         for (let j in arr2){
//             if (arr1[i] === arr2[j]) arr2.splice(j, 1);
//         }

//     }
//     if (arr2.length === 0)     console.log("true");
    
// }
const isAnagram = (arg1, arg2)=>{

    let arr1 =arg1.split("").to;
    let arr2 =arg2.split("");
    for (let i in arr1){
        for (let j in arr2){
            if (arr1[i] === arr2[j]) arr2.splice(j, 1);
        }

    }
    if (arr2.length == 0) return true;
    else return false;
    
}
console.log(isAnagram("wGgEGfKStgBMzaMdChn","zhMaGCnKwgEfMSgGtdG"))