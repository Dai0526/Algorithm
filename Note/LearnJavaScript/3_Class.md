# Class
Quoting MDN:  
“Classes are primarily syntactic sugar over Javascript's **existing prototype-based inheritance**. The class syntax **does not** introduce a new object-oriented inheritance model to JavaScript.”

### prototype-based inheritance
```
function Person(name,age) {
  this.name = name;
  this.age = age;
}

Person.prototype.greet = function(){
  console.log("Hello, my name is " + this.name);
}

const alberto = new Person("Alberto", 26);
const caroline = new Person("Caroline",26);

alberto.greet();
// Hello, my name is Alberto
caroline.greet();
// Hello, my name is Caroline
```
A new method called `greet` is added to the prototype in order to make it accessible to all the new instances of Person that we created.

## Create a class
```
// class declaration
class Person {

}

// class expression
const person = class Person {
}
```
Remember: class declaration (and expression) are not hoisted, which means that unless you want to get a ReferenceError you need to declare your class before you access it.

### Constructor
```
class Person {
  constructor(name,age){
    this.name = name;
    this.age = age;
  }
  greet(){
    console.log(`Hello, my name is ${this.name} and I am ${this.age} years old` );
  } // no commas in between methods
  farewell(){
    console.log("goodbye friend");
  }
}

const alberto = new Person("Alberto",26);

alberto.greet();
// Hello, my name is Alberto and I am 26 years old
alberto.farewell();
// goodbye friend
```

## Static Methods
Call by className.function(...)

```
class Person {
  constructor(name,age){
    this.name = name;
    this.age = age;
  }
  static info(){
    console.log("I am a Person class, nice to meet you");
  }
}

const alberto = new Person("Alberto",26);

alberto.info();    // TypeError: alberto.info is not a function

Person.info();     // Correct
```

## Setter and getter
```
class Person {
  constructor(name,surname) {
    this.name = name;
    this.surname = surname;
    this.nickname = "";
  }
  set nicknames(value){
    this.nickname = value;
    console.log(this.nickname);
  }
  get nicknames(){
     console.log(`Your nickname is ${this.nickname}`);
  }
}

const alberto = new Person("Alberto","Montalesi");

// first we call the setter
alberto.nicknames = "Albi";
// "Albi"

// then we call the getter
alberto.nicknames;
// "Your nickname is Albi"
```

## Extending class (inheritence)
class A extends B  
{  
...  
...  
... 
}

```
// our initial class
class Person {
  constructor(name,age){
    this.name = name;
    this.age = age;
  }
  greet(){
    console.log(`Hello, my name is ${this.name} and I am ${this.age} years old` );
  }
}


// our new class
class Adult extends Person {
  constructor(name,age,work){
    super(name, age);
    this.work = work;
  }
}

const alberto = new Adult("Alberto",26,"software developer");
```

### Extend std objects - Array
```
class Classroom extends Array {
  // we use rest operator to grab all the students
  constructor(name, ...students){
    // we use spread to place all the students in the array individually otherwise we would push an array into an array
    super(...students);
    this.name = name;
    // we create a new method to add students
  }
  add(student){
    this.push(student);
  }
}
const myClass = new Classroom('1A',
  {name: "Tim", mark: 6},
  {name: "Tom", mark: 3},
  {name: "Jim", mark: 8},
  {name: "Jon", mark: 10},
);

// now we can call
myClass.add({name: "Timmy", mark:7});
myClass[4];
// Object { name: "Timmy", mark: 7 }

// we can also loop over with for of
for(const student of myClass) {
  console.log(student);
  }
// Object { name: "Tim", mark: 6 }
// Object { name: "Tom", mark: 3 }
// Object { name: "Jim", mark: 8 }
// Object { name: "Jon", mark: 10 }
// Object { name: "Timmy", mark: 7 }
```