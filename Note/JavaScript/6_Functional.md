# Functional Programming

## Program State
### Conventional

There are 6 variables(global) are accessible.
1. movieList
2. titles
3. nolanMovieCount
4. bestTitles
5. ratingSum
6. averageRating  
They form the state of the program, and any assignment will to any one of it will change the state.

```javascript
const titles = [];
for (const movie of movieList) {
  titles.push(movie.title);
}
console.log(titles);

// Count movies by Christopher Nolan
const nolanMovieList = [];
for (const movie of movieList) {
  if (movie.director === "Christopher Nolan") {
    nolanMovieList.push(movie);
  }
}
console.log(nolanMovieList.length);

// Get titles of movies with an IMDB rating greater or equal to 7.5
const bestTitles = [];
for (const movie of movieList) {
  if (movie.imdbRating >= 7.5) {
    bestTitles.push(movie.title);
  }
}
console.log(bestTitles);

// Compute average movie rating of Christopher Nolan's movies
let ratingSum = 0;
let averageRating = 0;
for (const movie of nolanMovieList) {
  ratingSum += movie.imdbRating;
}
averageRating = ratingSum / nolanMovieList.length;
console.log(averageRating);

```


### Limiting Mutations with const Variables
In order to decrease the risk of accidental state mutation, a first step is to favor const over let whenever applicable for variable declarations. A variable declared with the const keyword cannot be further reassigned. Array and object content can still be mutated, though. Check the following code for details.

```javascript
const n = 10;
const fruit = "Banana";
const obj = {
  myProp: 2
};
const animals = ["Elephant", "Turtle"];

obj.myProp = 3; // Mutating a property is OK even for a const object
obj.myOtherProp = "abc"; // Adding a new property is OK even for a const object
animals.push("Gorilla"); // Updating content is OK even for a const array

n++; // Illegal
fruit = "orange"; // Illegal
obj = {}; // Illegal
animals = ["Bee"]; // Illegal

```
### Example
Thus, we can use this to secure the state of our program.
The following program limit to two variables:  
1. nolanMovieList
2. movieList

```javascript
const nolanMovieList = [];

// Get movies by Christopher Nolan
const nolanMovies = () => {
  for (const movie of movieList) {
    if (movie.director === "Christopher Nolan") {
      nolanMovieList.push(movie);
    }
  }
};

// Get titles of movies with an IMDB rating greater or equal to 7.5
const bestTitles = () => {
  const bestTitles = [];
  for (const movie of movieList) {
    if (movie.imdbRating >= 7.5) {
      bestTitles.push(movie.title);
    }
  }
  return bestTitles;
};

// Compute average rating of Christopher Nolan's movies
const averageNolanRating = () => {
  let ratingSum = 0;
  for (const movie of nolanMovieList) {
    ratingSum += movie.imdbRating;
  }
  return ratingSum / nolanMovieList.length;
};

console.log(titles());
nolanMovies();
console.log(nolanMovieList.length);
console.log(bestTitles());
console.log(averageNolanRating());
```

## Pure Functions
A pure function is a function that has the following characteristics:  
* Its outputs depend solely on its inputs
* It has no side effect  

A side effect is a change in program state or an interaction with the outside world. A database access or a console.log() statement are examples of side effects.

Given the same data, a pure function will always produce the same result. By design, a pure function is independent from the program state and must not access it. Such a function must accept parameters in order to do something useful. The only way for a function without parameters to be pure is to return a constant value.

**See [examples](https://github.com/Dai0526/Algorithm/tree/master/Note/LearnJavaScript/Example/Functional)**


## Array Operations
The `map()` method takes an array as a parameter and creates a new array with the results of calling a provided function on every element in this array. A typical use of map() is to replace a loop for array traversal. Let’s see map() in action.
```javascript
const numbers = [1, 5, 10, 15];
// The associated function multiply each array number by 2
const doubles = numbers.map(x => x * 2);

console.log(numbers); // [1, 5, 10, 15] (no change)
console.log(doubles); // [2, 10, 20, 30]
```

Improve Movie Example:
```Javascript
const titles = movies => {
  /* Previous code
  const titles = [];
  for (const movie of movies) {
    titles.push(movie.title);
  }
  return titles;
  */

  // Return a new array containing only movie titles
  return movies.map(movie => movie.title);
};
```


The `filter()` method offers a way to test every element of an array against a provided function. Only elements that pass this test are added to the returned array.
```Javascript
const numbers = [1, 5, 10, 15];
// Keep only the number greater than or equal to 10
const bigOnes = numbers.filter(x => x >= 10);

console.log(numbers); // [1, 5, 10, 15] (no change)
console.log(bigOnes); // [10, 15]
```
Improve Movie Example:
```Javascript
// Get movies by Christopher Nolan
const nolanMovies = movies => {
  /* Previous code
  const nolanMovies = [];
  for (const movie of movies) {
    if (movie.director === "Christopher Nolan") {
      nolanMovies.push(movie);
    }
  }
  return nolanMovies;
  */
  // Return a new array containing only movies by Christopher Nolan
  return movies.filter(movie => movie.director === "Christopher Nolan");
};

```

The `reduce()` method applies a provided function to each array element in order to reduce it to one value. This method is typically used to perform calculations on an array.

```Javascript
const numbers = [1, 5, 10, 15];
// Compute the sum of array elements
const sum = numbers.reduce((acc, value) => acc + value, 0);

console.log(numbers); // [1, 5, 10, 15] (no change)
console.log(sum);     // 31
```
The reduce() method can take several parameters:  
1. The first one is the function associated to reduce() and called for each array element. It takes two parameters: the first is an accumulator which contains the accumulated value previously returned by the last invocation of the function. The other function parameter is the array element.  
2. The second one is the initial value of the accumulator (often 0).

```Javascript
// Compute average rating of a movie list
const averageRating = movies => {
  /* Previous code
  let ratingSum = 0;
  for (const movie of movies) {
    ratingSum += movie.imdbRating;
  }
  return ratingSum / movies.length;
  */

  // Compute the sum of all movie IMDB ratings
  const ratingSum = movies.reduce((acc, movie) => acc + movie.imdbRating, 0);
  return ratingSum / movies.length;
};
```

At Last, the Movie.js is the eventual version:
```Javascript
const movieList = require("./MovieData.json");

const titles = movies => movies.map(movie => movie.title);
const byNolan = movie => movie.director === "Christopher Nolan";
const filter = (movies, func) => movies.filter(func);
const goodRating = movie => movie.imdbRating >= 7.5;
const ratings = movies => movies.map(movie => movie.imdbRating);
const average = array => array.reduce((sum, value) => sum + value, 0) / array.length;

console.log(titles(movieList));
const nolanMovieList = filter(movieList, byNolan);
console.log(nolanMovieList.length);
console.log(titles(filter(movieList, goodRating)));
console.log(average(ratings(nolanMovieList)));
```