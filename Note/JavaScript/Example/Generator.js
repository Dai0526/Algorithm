// 1. General Generator
function* fruitList(){
  yield 'Banana';
  yield 'Apple';
  yield 'Orange';
}

const fruits = fruitList();

fruits;
// Generator
console.log(fruits.next());
// Object { value: "Banana", done: false }
console.log(fruits.next());
// Object { value: "Apple", done: false }
console.log(fruits.next());
// Object { value: "Orange", done: false }
console.log(fruits.next());
// Object { value: undefined, done: true }

// 2. create an array of fruits
const fruitListArry = ['Banana','Apple','Orange','Melon','Cherry','Mango'];

// create our looping generator
function* loop(arr) {
  for (const item of arr) {
    yield `I like to eat ${item}s`;
  }
}

// 3. Return to terminate generator
const fruitGenerator = loop(fruitListArry);
console.log(fruitGenerator.next());
// Object { value: "I like to eat Bananas", done: false }
console.log(fruitGenerator.next());
// Object { value: "I like to eat Apples", done: false }
console.log(fruitGenerator.next().value);
// "I like to eat Oranges"


const fruits2 = fruitList();
console.log(fruits2.return());
console.log(fruits2.next());
// Object { value: undefined, done: true 

// 4. catch exception
function* gen(){
  try {
    yield "Trying...";
    yield "Trying harder...";
    yield "Trying even harder..";
  }
  catch(err) {
    console.log("Error: " + err );
  }
}

const myGenerator = gen();
console.log(myGenerator.next());
// Object { value: "Trying...", done: false }
console.log(myGenerator.next());
// Object { value: "Trying harder...", done: false }
console.log(myGenerator.throw("ooops"));
// Error: ooops
// Object { value: undefined, done: true }

