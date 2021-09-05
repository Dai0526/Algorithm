const movieList = [
    {
      title: "Batman",
      year: 1989,
      director: "Tim Burton",
      imdbRating: 7.6
    },
    {
      title: "Batman Returns",
      year: 1992,
      director: "Tim Burton",
      imdbRating: 7.0
    },
    {
      title: "Batman Forever",
      year: 1995,
      director: "Joel Schumacher",
      imdbRating: 5.4
    },
    {
      title: "Batman & Robin",
      year: 1997,
      director: "Joel Schumacher",
      imdbRating: 3.7
    },
    {
      title: "Batman Begins",
      year: 2005,
      director: "Christopher Nolan",
      imdbRating: 8.3
    },
    {
      title: "The Dark Knight",
      year: 2008,
      director: "Christopher Nolan",
      imdbRating: 9.0
    },
    {
      title: "The Dark Knight Rises",
      year: 2012,
      director: "Christopher Nolan",
      imdbRating: 8.5
    }
  ];

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
  