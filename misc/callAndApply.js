const obj1 = {
  name: "Junaid",
};
const obj2 = {
  name: "Junnu",
  sayMyName() {
    return this.name;
  },
};
let lostContext = obj2.sayMyName;
//*without func.call()
console.log(lostContext());
//*func.call(context,...args)
console.log(lostContext.call(obj1));
console.log(lostContext.call(obj2));
