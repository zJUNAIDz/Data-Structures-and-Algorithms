// var Vector = function (arr1:number[]) {
//   add = function (arr2:number[]) {
//     if()
//   };
// };
class Vector {
  arr1: number[];
  constructor(arr1: number[]) {
    this.arr1 = arr1;
  }
  add(arr2: Vector): Vector {
    if (this.arr1.length != arr2.arr1.length)
      throw console.error("OOPS! Array length are not same...");
    let ans: number[] = [];
    for (let i = 0; i < this.arr1.length; i++) {
      ans[i] = this.arr1[i] + arr2.arr1[i];
    }
    return new Vector(ans);
  }
  subtract(arr2: Vector): Vector {
    if (this.arr1.length != arr2.arr1.length)
      throw console.error("OOPS! Array length are not same...");
    let ans: number[] = [];
    for (let i = 0; i < this.arr1.length; i++) {
      ans[i] = this.arr1[i] - arr2.arr1[i];
    }
    return new Vector(ans);
  }
  dot(arr2: Vector): number {
    if (this.arr1.length != arr2.arr1.length)
      throw console.error("OOPS! Array length are not same...");
    let ans: number = 0;
    for (let i = 0; i < this.arr1.length; i++) {
      ans += this.arr1[i] * arr2.arr1[i];
    }
    return ans;
  }
  norm(): number {
    let ans: number = 0;
    for (let i = 0; i < this.arr1.length; i++) {
      ans += this.arr1[i] ** 2;
    }
    return Math.sqrt(ans);
  }
  equals(arr2: Vector): boolean {
    if (this.arr1.length != arr2.arr1.length)
      // throw console.error("OOPS! Array length are not same...");
    for (let i = 0; i < this.arr1.length; i++) {
      if (this.arr1[i] != arr2.arr1[i]) return false;
    }
    return true;
  }
  toString(): string {
    return String(this.arr1);
  }
}
var a = new Vector([1, 2, 3]);
var b = new Vector([3, 4, 5]);
var c = new Vector([5, 6, 7, 8]);
console.log(a.toString());
