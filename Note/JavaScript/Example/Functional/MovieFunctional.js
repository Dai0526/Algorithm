const movieList = require("./MovieData.json");

// Get movie titles
const titles = () => {
    const titles = [];
    for (const movie of movieList) {
      titles.push(movie.title);
    }
    return titles;
  };
  
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
  