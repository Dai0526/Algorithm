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

console.log(myCar.getType());
console.log(myCar.getTypeFuncion()());
console.log(myCar.getTypeClosureFuncion()());


console.log("\r\nUnexpected behavior of variables in closures.")
console.log("Example: \r\n")

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

  /* 
  output
  0: 9
  1: 9
  2: 9
  */

console.log("\r\nFix with define argument")
function giveMeFunctionsFixed() {
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

myFunctions = giveMeFunctionsFixed();
for (var i = 0; i < myFunctions.length; i++) {
  console.log(i + ": " + myFunctions[i]());
}

  /* 
  output
    0: 0
    1: 1
    2: 4
  */