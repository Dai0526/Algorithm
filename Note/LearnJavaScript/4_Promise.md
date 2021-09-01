# Promise
JavaScript work **synchronously** which means that each block of code will be executed after the previous one.  
Data Racing example
```
const data = fetch('your-api-url-goes-here');
console.log('Finished');
console.log(data);
```
It will print `undefined`. Because `fetch` performs asynchronously, which means that the code won’t stop running once it hits that line but, instead, will continue executing.  

What we need is a way of waiting until fetch returns us something before we continue executing our code.

To avoid this we would use `callbacks` or `promises`.

### callback hell
Happens when we try to write asynchronous code as if it were synchronous, meaning that we try to chain each block of code after the other. e.g.  
    
    do A, If A do B, if B do C and so on and so forth.

```Javascript
const makePizza = (ingredients, callback) => {
    mixIngredients(ingredients, function(mixedIngredients)){
      bakePizza(mixedIngredients, function(bakedPizza)){
        console.log('finished!')
      }
    }
}
```

## Promise
A `Promise` is an object representing the eventual completion or failure of an asynchronous operation.

`resolve` and `reject` will be called once the promise is finished.  

`setTimeout()` to wait a certain time before resolving.

```Javascript
const myPromise = new Promise((resolve, reject) => {
  setTimeout(() => {
      resolve("The value we get from the promise");
      //reject(Error("this is our error"));
    }, 2000); // set timeout
});

myPromise.then(
  data => {
    console.log(data);
  })
  .catch(err => {
      console.error(err);
  });
// The value we get from the promise
```

We use `.then()` to grab the value when the promise resolves and `.catch()` when the promise rejects.

Looking at our error log, you can see that it tells us where the error occurred. That’s because we wrote reject(Error("this is our error")); and not simply reject("this is our error");.


## Chaining promises
```Javascript
const myPromise = new Promise((resolve, reject) => {
  resolve();
});

myPromise
  .then(data => {
    // return something new 
    return 'working...'
  })
  .then(data => {
    // log the data that we got from the previous promise
    console.log(data);

    throw 'failed!';
  })
  .catch(err => {
    // grab the error from the previous promise and log it
    console.error(err);
    // failed!
  })
```

As you can see, the first `then` passed a value down to the second one where we logged it and also threw an error that was caught in the `catch` clause.

We’re not limited to chaining in case of success, we can also chain when we get a `reject`.

```Javascript
const myPromise = new Promise((resolve, reject) => {
  resolve();
});

myPromise
  .then(data => {
    throw new Error("ooops");

    console.log("first value");
  })
  .catch(() => {
    console.log("catch an error");
  })
  .then(data => {
  console.log("second value");
  });
  // catch an error
  // second value
```
We did not get “first value” because we threw an error therefore we only got the first `.catch()` and the last `.then()`.

### Promise.resolve() and Promise.reject()
```Javascript
//Promise.resolve()
Promise.resolve('Success').then(function(value) {
  console.log(value);
  // "Success"
}, function(value) {
  // not called
});

// Promise.reject()
Promise.reject(new Error('fail')).then(function() {
  // not called
}, function(error) {
  console.log(error);
  // Error: fail
});
```

### Promise.all() and Promise.race()
* Promise.all() returns a single Promise that resolves when all promises have resolved.
    ```Javascript
    const promise1 =  new Promise((resolve,reject) => {
    setTimeout(resolve, 500, 'first value');
    });
    const promise2 =  new Promise((resolve,reject) => {
    setTimeout(resolve, 1000, 'second value');
    });

    promise1.then(data => {
    console.log(data);
    });
    // after 500 ms
    // first value
    promise2.then(data => {
    console.log(data);
    });
    // after 1000 ms
    // second value
    
    // use promise.all()
    const promise1 =  new Promise((resolve,reject) => {
    setTimeout(resolve, 500, 'first value');
    });
    const promise2 =  new Promise((resolve,reject) => {
    setTimeout(resolve, 1000, 'second value');
    });

    Promise
    .all([promise1, promise2])
    .then(data => {
        const[promise1data, promise2data] = data;
        console.log(promise1data, promise2data);
    });
    // after 1000 ms
    // first value second value
    
    ```
Our values returned together, after 1000ms (the timeout of the second promise). This means that the first one had to wait for the completion of the second one.

If we were to pass an empty iterable then it will return an already resolved promise.

If one of the promises was rejected, then all of them would asynchronously reject with the value of that rejection even if they resolved.

```Javascript
const promise1 =  new Promise((resolve,reject) => {
  resolve("my first value");
});
const promise2 =  new Promise((resolve,reject) => {
  reject(Error("oooops error"));
});

// one of the two promises will fail, but `.all` will return only a rejection.
Promise
  .all([promise1, promise2])
  .then(data => {
    const[promise1data, promise2data] = data;
    console.log(promise1data, promise2data);
  })
  .catch(err => {
    console.log(err);
  });
  // Error: oooops error
```

* Promise.race() on the other hand returns a promise that resolves or rejects as soon as one of the promises in the iterable resolves or rejects with the value from that promise.
```Javascript
const promise1 =  new Promise((resolve,reject) => {
  setTimeout(resolve, 500, 'first value');
});
const promise2 =  new Promise((resolve,reject) => {
  setTimeout(resolve, 100, 'second value');
});

Promise.race([promise1, promise2]).then(function(value) {
  console.log(value);
  // Both resolve, but promise2 is faster
});
// expected output: "second value"
```