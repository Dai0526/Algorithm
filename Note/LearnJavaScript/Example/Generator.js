// create an array of fruits
const fruitList = ['Banana','Apple','Orange','Melon','Cherry','Mango'];

// create our looping generator
function* loop(arr) {
  for (const item of arr) {
    yield `I like to eat ${item}s`;
  }
}


const fruitGenerator = loop(fruitList);
console.log(fruitGenerator.next());
// Object { value: "I like to eat Bananas", done: false }
console.log(fruitGenerator.next());
// Object { value: "I like to eat Apples", done: false }
console.log(fruitGenerator.next().value);
// "I like to eat Oranges"