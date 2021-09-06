// write a function that returns the titles of movies that were released before 2000.
const movieList = require("./Data.json");

const releaseBeforeYear = (movie, year) => movie.year < year;
const filters = (movies, filterFunc, year) => movies.filter( movie => filterFunc(movie, year));
const titles = movie => movie.map(m => m.title);

const before2k = titles(filters(movieList, releaseBeforeYear, 2000));
console.log(before2k);