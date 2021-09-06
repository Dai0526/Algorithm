const a = ["tomato","cucumber","beans"];
const b = ["pork","beef","chicken"];

console.log("\r\nCombine array: ");
const menu = [...a, "pasta", ...b];
console.log(menu);
// Array [ "tomato", "cucumber", "beans", "pasta", "pork", "beef", "chicken" ]


const veggie = ["tomato","cucumber","beans"];
const newVeggie = veggie;

console.log("\r\nNot Copy. Point to Memory: ");
// this may seem like we created a copy of the veggie array but look now
veggie.push("peas");
console.log(veggie);
// Array [ "tomato", "cucumber", "beans", "peas" ]

console.log(newVeggie);
// Array [ "tomato", "cucumber", "beans", "peas" ]

console.log("\r\nCopy by Creating a new array: ");

const veggie1 = ["tomato","cucumber","beans"];
// we created an empty array and put the values of the old array inside of it
const newVeggie1 = [].concat(veggie1);
veggie1.push("peas");
console.log(veggie1);
// Array [ "tomato", "cucumber", "beans", "peas" ]
console.log(newVeggie1);
// Array [ "tomato", "cucumber", "beans" ]

console.log("\r\nSpread: ");
const veggie2 = ["tomato","cucumber","beans"];
const newVeggie2 = [...veggie2];
veggie.push("peas");
console.log(veggie2);
// Array [ "tomato", "cucumber", "beans", "peas" ]
console.log(newVeggie2);
// Array [ "tomato", "cucumber", "beans" ]


console.log("\r\nUse Rest to split array: ");
const runners = ["Tom", "Paul", "Mark", "Luke"];
const [first,second,...losers] = runners;

console.log(...losers);
// Mark Luke
