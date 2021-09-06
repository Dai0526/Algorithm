const movieList = require("./MovieData.json");

// Get movie titles
const titles = movies => {
    const titles = [];
    for (const movie of movies) {
      titles.push(movie.title);
    }
    return titles;
  };
  
  // Get movies by Christopher Nolan
  const nolanMovies = movies => {
    const nolanMovies = [];
    for (const movie of movies) {
      if (movie.director === "Christopher Nolan") {
        nolanMovies.push(movie);
      }
    }
    return nolanMovies;
  };
  
  // Get titles of movies with an IMDB rating greater or equal to 7.5
  const bestTitles = movies => {
    const bestTitles = [];
    for (const movie of movies) {
      if (movie.imdbRating >= 7.5) {
        bestTitles.push(movie.title);
      }
    }
    return bestTitles;
  };
  
  // Compute average rating of a movie list
  const averageRating = movies => {
    let ratingSum = 0;
    for (const movie of movies) {
      ratingSum += movie.imdbRating;
    }
    return ratingSum / movies.length;
  };
  
  console.log(titles(movieList));
  const nolanMovieList = nolanMovies(movieList);
  console.log(nolanMovieList.length);
  console.log(bestTitles(movieList));
  console.log(averageRating(nolanMovieList));
  