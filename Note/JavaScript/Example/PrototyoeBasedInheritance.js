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