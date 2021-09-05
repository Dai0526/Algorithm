const movieList = require("./MovieData.json");

// Get movie titles
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

  // Get titles of movies with an IMDB rating greater or equal to 7.5
const bestTitles = movies => {
    /* Previous code
    const bestTitles = [];
    for (const movie of movies) {
      if (movie.imdbRating >= 7.5) {
        bestTitles.push(movie.title);
      }
    }
    return bestTitles;
    */
  
    // Filter movies by IMDB rating, then creates a movie titles array
    return movies.filter(movie => movie.imdbRating >= 7.5).map(movie => movie.title);
  };

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
    //const ratingSum = movies.map(movie => movie.imdbRating).reduce((acc, value) => acc + value, 0);

    return ratingSum / movies.length;
  };

