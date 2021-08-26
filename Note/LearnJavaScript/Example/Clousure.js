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