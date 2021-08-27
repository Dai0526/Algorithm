## Variables

Define a Variable
```
var name = "Tom"
let name = "Tom"
const name = "Tom"
```

Naming Convention:  
1. Both Camel or Snake cases are good.   
2. Consistent
```
let userId = ''    # Camel
let user_id = ''   # Snake
```

## Data Type
JavaScript is a dynamic language, and you don’t have to define the type of variables when you define them.

```
let user_id;
user_id = int 12;       # number
user_id = "string 12"   # string
```

### Primitives
* string
* number
* boolean
* null
* undefined
* symbol

#### String Method
1. indexOf()
2. slice()
3. toUpperCase()
4. toLowerCase()
5. startsWith()
6. endsWith()
7. includes()
8. repeat()


### Object
Can hold values and methods

```
const car = {
    wheels: 4,
    color: "read",
    drive: function(){
        console.log("wroom wroom")
    }
}

console.log(Object.keys(car)[0])        // wheels
console.log(typeof Object.keys(car)[0]) // string
car.drive();                            // wroom wroom
```

Create Empty Object - Without properties
```
const car = new Object();
const car = {}

car.color = 'red'
console.log(car) // {color: "red"}
```

Remove a properties from an object
```
const car = {
    wheels: 4,
    color: "read",
};

delete car.color;
```

Iterating through object properties
```
var student = {
  name: "Mary", 
  age: 10, 
  grades: [90, 88, 95]
}

for(property in student) {
  console.log(property);
}

// name
// age
// grades
```

Print Value of properties in the object
```
for(property in student) {
  //bracket notation does
  console.log(student[property]);
}

// Mary
// 10
// [ 90, 88, 95 ]
```

#### Constructor
```
var Student = function(name, age) {
  this.name = name; 
  this.age = age;
  this.birthday = function(){
   this.age++;
  }
}
```

#### Object Type
All objects in JavaScript set out as nonspecific groups of data and related functionality. You create instances by utilizing a new operator that is followed by the name of the object type (constructor function).

The easiest way to instantiate objects is the Object() constructor that accepts an optional value as its argument. This value is stored as the wrapped value of the object, and it can be accessed through the valueOf() function.

If you do not use the constructor argument or specify either null or undefined, an empty object will be used as the wrapped object value:
```
var obj1 = new Object();
var obj2 = new Object(null);
var obj3 = new Object(undefined);
var obj4 = new Object(12.3);
var obj5 = new Object(true);
var obj6 = new Object("Hi");
console.log(obj1.valueOf()); // Object {}
console.log(obj2.valueOf()); // Object {}
console.log(obj3.valueOf()); // Object {}
console.log(obj4.valueOf()); // 12.3
console.log(obj5.valueOf()); // true
console.log(obj6.valueOf()); // Hi
```

#### Object - Instance Properties and method

| Method | Description |
| --- | --- |
| hasOwnProperty() | Indicates if the given property specified in the function argument exists on the object instance(not on the prototype) |
| isPropertyOf() | Checks whether the object specified in the argument is a prototype of another object |
| propertyIsEnumerable() | Indicates if the given property can be enumerated using the for-in statement |
| toLocaleString() | Returns a string representation of the object |
| valueOf() | Returns a string, number, or Boolean equivalent of the object. It oftens the same value as toString() |

### Array

* push(var) - add item to the end of array
* pop() - remove last item
* shift() - remove first item
* unshift(var) - add item to beginning
* toString() - print

```
const fruitBasket = ['apple','banana','orange']
// get the length of the Array
console.log(fruitBasket.length); // 3

// add a new value at the end of the array
fruitBasket.push('pear')
console.log(fruitBasket); // ["apple", "banana", "orange", "pear"]

// add a new value at the beginning of the array
fruitBasket.unshift('melon')
console.log(fruitBasket); // ["melon", "apple", "banana", "orange", "pear"]

// remove a value from the end of the array
fruitBasket.pop()
console.log(fruitBasket); // ["melon", "apple", "banana", "orange"]

// remove a value from the beginning of the array
fruitBasket.shift()
console.log(fruitBasket); // ["apple", "banana", "orange"]
```

**Array is Object!!**  
`null` is a primitive type, but the type of null is `object`  

  

## Logic Operator
* AND - `&&`
* Or  - `||`
* Not - `!`

### `==` and `===`
1. `==` compares value, `===` compares object
2. When comparing different types,  
    * `===` always return false
    * `==` will convert one to the same type then compare value
        ```
        var ageOfBill = 10;
        var ageOfSally = "10";
        console.log(ageOfBill == ageOfSally);  // true
        ```

## Undefined and Null
Variables with a null type, on the other hand, represent values that are intentionally empty. A null variable can be created by setting the variable equal to null.  

Variables are only stored as undefined if they have been declared but not instantiated with a value.

Null values intentionally are stored as null to indicate that the variable is empty. You should set a variable equal to null if and only if the variable is expected to have no value.

## Functions
**Function are variable**
```
var sum = function(x, y){ return x + y; };
var subtract = function(x, y){ return x - y; };
var multiply = function(x, y){ return x * y; };
var divide = function(x, y){ return x / y; };

//functions can be stored in an array
var operations = [sum, subtract, multiply, divide];

//functions can be called from an array by accessing them and using the () operator
for(var i = 0; i < operations.length; i++){
  console.log(operations[i](5,10));
}
```
Put Function collections in Object
```
//functions can be stored in an object as property values
var operations = {
  sum: function(x, y){ return x + y; }, 
  subtract: function(x, y){ return x - y; }, 
  multiply: function(x, y){ return x * y; }, 
  divide: function(x, y){ return x / y; }
};

//functions can be called from an object by accessing a property (dot or bracket)
//and using then the () operator
console.log(operations.multiply(5, 10));
console.log(operations["multiply"](5, 10));

```

### Default function arguments
```
function calculatePrice(total, tax = 0.1, tip = 0.05){
  console.log(total + (total * tax) + (total * tip));
}
// In this case 0.15 will be bound to the tip
calculatePrice(100, undefined, 0.15)
```

We can futher improve it by **destructuring**

We made the argument of our function an object. When calling the function, we don’t even have to worry about the order of the parameters because they are matched based on their key.

```
function calculatePrice({
  total = 0,
  tax = 0.1,
  tip = 0.05} = {} ){
  console.log(total + (total * tax) + (total * tip));
}

const bill = calculatePrice({ tip: 0.15, total:150 });
// 187.5
```
In the example above, the default value for tip was 0.05, and we overwrote it with 0.15. But we didn’t give a value to tax which remained the default 0.1.  
Notice:
```
{
  total = 0,
  tax = 0.1,
  tip = 0.05
} = {}
```
If we don’t default our argument object to an empty object, and we were to try and run calculatePrice(), we would get:  
&nbsp;&nbsp;&nbsp;&nbsp;`Cannot destructure property total of 'undefined' or 'null'.`




### Arrow Function
ES6 introduced fat arrows (`=>`) as a way to declare functions. This is how we would normally declare a function in ES5:
```
const greeting1 = function(name) {
  console.log("hello " + name);
}

var greeting2 = (name) => {
  console.log(`hello ${name}`);
}

// if there is only one parameter
var greeting = name => {
  console.log(`hello ${name}`);
}
```

#### **When to Avoid Arrow Functions**

**this** keyword
- When you use an arrow function, the this keyword is inherited from the parent scope.

Using what we know about the inheritance of the `this` keyword we can define some instances where you should not use arrow functions.

The next two examples show when to be careful using `this` inside of arrows.  

Example 1

```
const button = document.querySelector("btn");
button.addEventListener("click", () => {
  // error: *this* refers to the `Window` Object
  this.classList.toggle("on");
})
```

Example 2  
```
const person1 = {
  age: 10,
  grow: function() {
    this.age++;
    console.log(this.age);
  }
}

person1.grow();
// 11

const person2 = {
  age: 10,
  grow: () => {
    // error: *this* refers to the `Window` Object
    this.age++;
    console.log(this.age);
  }
}

person2.grow();
```

Another difference between arrow functions and normal functions is the access to the arguments object. The arguments object is an array-like object that we can access from inside functions and contains the values of the arguments passed to that function.

```
function example(){
  console.log(arguments[0])
}

example(1,2,3);
// 1
```
As you can see we accessed the first argument using an array notation arguments[0].

Similarly to what we saw with the this keyword, arrow functions inherit the value of the arguments object from their parent scope.

Example: exception
```
 const showWinner = () => {
  const winner = arguments[0];
  console.log(`${winner} was the winner`)
}

showWinner( "Usain Bolt", "Justin Gatlin", "Asafa Powell" )

// () means no argument, it will throw 'ReferenceError: arguments is not defined'
```
One work around is to sue spread operator `...`

```
const showWinner = (...args) => {
  const winner = args[0];
  console.log(`${winner} was the winner`)
}
showWinner("Usain Bolt", "Justin Gatlin", "Asafa Powell" )  // "Usain Bolt was the winner"

// The above function is equivalent to 
const showWinner = function() {
  const winner = arguments[0];
  console.log(`${winner} was the winner`)
}
showWinner("Usain Bolt", "Justin Gatlin", "Asafa Powell")  // "Usain Bolt was the winner"

```

## Regular Expression

```
var pattern = /[A-Z]{3}-\d{3}/gi;
```

The pattern part is `[A-Z]{3}-\d{3}`, and it matches every string that starts with three letters in the “A”-“Z” range, followed by a dash, and closed by three decimal digits. The `/gi` is the part of the flag, where g indicates global mode (the pattern will be applied to the whole string instead of stopping after the first match is found), and i indicates case-insensitive mode (the case of the pattern and the string are ignored when determining matches).

```
var pattern = new RegExp("[A-Z]{3}-\\d{3}", "gi");
```