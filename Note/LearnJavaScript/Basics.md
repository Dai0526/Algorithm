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

### Array
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



