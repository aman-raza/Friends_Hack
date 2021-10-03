import React from 'react';

const MovieCard = ({movie}) => {
    return ( 
        <div className="card">
            <img 
            className="card--image"
            src={`https://image.tmdb.org/t/p/w185_and_h278_bestv2/${movie.poster_path}`}
            alt={movie.title + ' poster'} 
            />
            <h3 className="card--title">{movie.title}</h3>
            <p><small>RELEASE DATE: {movie.release_date}</small></p>
            <p><small>RATING: {movie.vote_average}</small></p>
            <p className="card--desc">{movie.overview}</p>
        </div>
     );
}
 
export default MovieCard;