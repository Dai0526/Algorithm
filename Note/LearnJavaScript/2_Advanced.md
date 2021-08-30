# Advanced

## Object Notation

Javascript Object Notation(`JSON`)   
JavaScript uses the JSON syntax, however, JSON is not a part of the ECMAScript specification.

```
var car = new Object();
car.manufacturer = "BMW";
car.type = "X5";
console.log(car);

// result
Object {manufacturer: "BMW", type: "X5"}
```

### JSON Syntax
Nestaed JSON example
```
{
  "id": 4234,
  "name": {
    "first": "John",
    "last": "Doe",
  },
  "enables": true
}

// equavilent to
[23, { "type": "S", "name": "Small" }, true]

```

### Serializing and Parsing JSON
This object is very simple for it has only two methods, `stringify()` and `parse()`.

* stringfy()  
    The `stringify()` method converts the specified value (**first argument**) into its JSON representation. The method accepts two other optional arguments, a replacer object (**second argument**), and a spacing value (**third argument**).  
    ```
    var orderJson = JSON.stringify(order, null, "  ");
    console.log(orderJson);
    ```
* parse()  
    The `parse()` method converts a JSON string into an object. The first argument of this method is the JSON string to be converted into an object, and it has a second, optional argument, which prescribes how the value originally produced by parsing is transformed, before being returned. 

    ```
    var remoteOrder = {
      "date": "11/20/2013",
      "customerId": 116,
      "items": [
        {
          "product": "Surface 4 Pro",
          "unitprice": "799",
          "amount": 1
        },
        {
          "product": "Type Cover 4",
          "unitprice": "129",
          "amount": 1
        },
        {
          "product": "Docking station",
          "unitprice": "199",
          "amount": 1
        }
      ]
    }

    var orderString = JSON.stringify(remoteOrder);
    var order = JSON.parse(orderString);

    console.log("Date: " + order.date);
    for (var i = 0; i < order.items.length; i++) {
      console.log("\r\n");
      console.log("Product: " + order.items[i].product);
      console.log("Unit price: " + order.items[i].unitprice);
      console.log("Amount: " + order.items[i].amount);
    }
    ```
Above code see .\Example\Advanced.js

### Remove Object Properties
`delete` Keyword
```
var myObject = new Object();
myObject.intProp = 23;
myObject.strProp = "Hi!";

console.log(myObject.intProp); // 23
console.log(myObject.strProp); // Hi!

delete myObject.intProp;

console.log(myObject.intProp); // undefined
console.log(myObject.strProp); // Hi!
```

### Modularity
Check `OOP`

## Specifying Function
```
var add = function (a, b) {
  return a + b;
}
```
**Because functions are objects, function expressions provide you a way to return a function from a function.**

```
var type = "subtract";
var op = getOperationFunc(type);
console.log(op(35, 23)); // 12

function getOperationFunc(type) {
  if (type == "add") {
    return function (a, b) {
      return a + b;
    };
  }
  else {
    return function (a, b) {
      return a - b;
    };
  }
}
```
Similar to C++/C's function pointer and C#'s delegates functions.

### Recursion
```
function fibonacci(index) {
      if (index == 0) return 0;
      if (index == 1) return 1;
      return fibonacci(index - 1) +
        fibonacci(index - 2);
    }
```

## Closures
**Functions that have access to variables from other function's scopes are called closures.**
```
var addOp = createOp("add");
// ...
console.log(addOp(23, 12));      // 35
```
When the `createOp` function is called, the context contains two items in its scope chain, the activation object of createOp and the global activation object.  

createOp (executation) -> CreateOp(argument+type) -> global(createOP + addOp + subtractOp)  

Earlier you learned that whenever a variable is accessed inside a function, the specified name is searched for in the scope chain. Once the function has completed, the local activation object is destroyed, leaving only the global scope in memory. **Closures, on the other hand, behave differently.**

A function that is defined inside another function adds the containing function’s activation object into its scope chain. This ensures that the internal function has access to the variables of the containing function. So, in createOp, the returned function’s scope chain includes the activation object for createOp. When the console.log() operation invokes the anonymous function through addOp, the execution context of addOp looks like as shown in the image below.

```
var type = "Mercedes"
var myCar = {
  type: "BMW",

  getType: function () {
    return this.type;
  },

  getTypeFuncion: function () {
    return function () {
      return this.type;
    }
  },

  getTypeClosureFuncion: function () {
    var thisInContext = this;
    return function () {
      return thisInContext.type;
    }
  }
};

console.log(myCar.getType());                 \\print BMW
console.log(myCar.getTypeFuncion()());        \\print undefine or Mercedes
console.log(myCar.getTypeClosureFuncion()()); \\print BMW
```
### Using variables in anonymous functions and closures
**Sometimes it is not obvious, but variables work in closures unexpectedly.**

```
function giveMeFunctions() {
      var functions = [];
      for (var i = 0; i < 3; i++) {
        functions[i] = function () {
          return i * i;
        }
      }
      return functions;
    }

    var myFunctions = giveMeFunctions();
    for (var i = 0; i < myFunctions.length; i++) {
      console.log(i + ": " + myFunctions[i]());
    }

  // Print 
  0 : 9
  1 : 9
  2 : 9
  ```

What’s wrong? Each anonymous function retrieves i*i where i goes from 0 to 2, so something strange must be happening! The code snippet suggests that i is evaluated every time the anonymous function is defined, but it does not work this way.

The anonymous function is evaluated when it is invoked and using the execution context it resolves the value of i, using the context’s scope chain. When you call giveMeFunctions(), the i variable is set to 3 at the time it returns.

As you iterate through the elements in the returned function array, the i*i expression is evaluated using the value of i, which happens to be 3 each time. That is why you see only nines in the output. There is a quick fix for this issue.

```
function giveMeFunctions() {
  var functions = [];
  for (var i = 0; i < 3; i++) {
    functions[i] = function (arg) {
      return function () {
        return arg * arg;
      }
    }(i);
  }
  return functions;
}


//print
0: 0
1: 1
2: 4
```

## Spread Operator and Rest Parameters
**Spread** syntax allows an iterable such as an array expression or string to be expanded in places where zero or more arguments (for function calls) or elements (for array literals) are expected, or an object expression to be expanded in places where zero or more key-value pairs (for object literals) are expected.

### Combine Array
```
const veggie = ["tomato","cucumber","beans"];
const meat = ["pork","beef","chicken"];

const menu = [...veggie, "pasta", ...meat];
console.log(menu);
// Array [ "tomato", "cucumber", "beans", "pasta", "pork", "beef", "chicken" ]
```

### Copy Array
* var a `=` b
  * `=` sign is just point to memory address, like `&` in C++.  
* var a = [].concat(b)
  * copy by creating a new array
* var a = [...b]
  * Spread to make a deep copy


#### Spread into function
```
// OLD WAY
function doStuff (x, y, z) {
  console.log(x + y + z);
 }
var args = [0, 1, 2];

// Call the function, passing args
doStuff.apply(null, args);

// USE THE SPREAD SYNTAX

doStuff(...args);
// 3 (0+1+2);
console.log(args);
// Array [ 0, 1, 2 ]
```

### Rest parameter
The **rest** syntax looks exactly the same as the **spread**- 3 dots `...`. But it is quite the opposite of it. **Spread** expands an array, while **rest** condenses multiple elements into a single one.
  
```
const runners = ["Tom", "Paul", "Mark", "Luke"];
const [first,second,...losers] = runners;

console.log(...losers);
// Mark Luke
```

We stored the first two values inside the const first and second and whatever was left we put inside losers using the rest parameter.

## Generator -> Iterator
A generator function is a function that we can start and stop, for an indefinite amount of time. And also restart with the possibility of passing additional data at a later point in time.  

In my opinion, it is an alternative of iterator. (iterator in Javascript requires customization)  

**GENERATOR**  
* we declared the function using `function*`
* we used the keyword `yield` before our content
* we start our function using `.next()`
* the last time we call `.next()` we receive and empty object and we get done: true
* Our function is paused between each `.next()` call.

General Example  
```
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
```

### Create generator for Array
```
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
```

### Finish Generator with Return
```
function* fruitList(){
  yield 'Banana';
  yield 'Apple';
  yield 'Orange';
}

const fruits = fruitList();

console.log(fruits.return());
// Object { value: undefined, done: true }
```

### Catching Error with Throw()
```
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
```

### Combine Generator with Promise

Using a `generator` in combination with a `Promise` will allow us to write asynchronous code that feels like synchronous code.

What we want to do is wait for a promise to resolve and then pass the resolved value back into our generator in the `.next()` call.

```
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
```
The first time we call `.next()` at line 15 it will call our promise and wait for it to resolve (in our simple example it resolves immediately). And when we call `.next()` again at line 20 it will utilize the value returned by the promise to do something else (in this case just interpolate a string).