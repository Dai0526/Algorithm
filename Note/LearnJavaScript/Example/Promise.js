// 1. Generator with Promise
const myPromise = () => new Promise((resolve) => {
  resolve("our value is...");
});

function* gen() {
  let result = "";
  // returns promise
  yield myPromise().then(data => { result = data }) ;
  // wait for the promise and use its value
  yield result + ' 2';
};

// Call the async function and pass params
const asyncFunc = gen(); 
const val1 = asyncFunc.next();
console.log(val1);
// call the promise and wait for it to resolve
// {value: Promise, done: false}
val1.value.then(() => {
  console.log(asyncFunc.next());
})
// Object { value: "our value is... 2", done: false }