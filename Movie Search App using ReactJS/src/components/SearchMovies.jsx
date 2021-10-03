import React, { useState } from 'react';
import MovieCard from '../components/movieCard';
const SearchMovies = () => {
    //state for query
    //the 'query' will be an empty string initially
    const [query, setQuery] = useState('');
    
    //state for movies
    //the 'movies' will be an empty array initially
    const [movies, setMovies] = useState([]);

    const searchMovies = async(e) => {
    //preventing the default behavior
    e.preventDefault();
    //making sure that the user has entered atleast some movie name in the 
    if(query === '') { return null;}
    
    //API KEY
    const url = `https://api.themoviedb.org/3/search/movie?api_key=8f582a5fd9895944f50ba1e1235bf348&language=en-US&query=${query}&page=1&include_adult=false`;

        try {
        //Using fetch API to get data
        const res = await fetch(url);
        const data = await res.json();

        //adding the movies data into setMovies
        setMovies(data.results);
        } catch(err) {
            console.error(err);
        }
    }
    return ( 
        <React.Fragment>
           <form className="form" onSubmit={searchMovies}>
               <label htmlFor="query" className="label">
                   Movie Name
               </label>
               <input 
                    type="text" 
                    className="input" 
                    name="query" 
                    placeholder="i.e. Jurassic Park" 
                    value={query} 
                    onChange={(e) => setQuery(e.target.value)}
               />
               <button type="submit" className="button">Search</button>
           </form>
           <div className="card-list">
               {movies.filter(movie => movie.poster_path).map(movie => (
                   <MovieCard
                        movie={movie}
                        key={movie.id}
                   />
               ))}
           </div>
        </React.Fragment>
     );
}
 
export default SearchMovies;