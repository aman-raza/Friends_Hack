#pragma once

#include <string>
#include "./exceptions.h"

class Book
{
	private:
		/// The title of the book
		std::string title = "";

		/// The author of the book
		std::string author = "";

		/// The genre of the book
		std::string genre = "";

		/// The release year of the book
		int releaseYear = 0;

	public:
		/// Book constructor
		Book(std::string title = "None", std::string author = "None", std::string genre = "None", int releaseYear = 0);

		/// Book destructor
		~Book();

		/// Title getter
		std::string getTitle() const { return this->title; }
		/// Title setter
		void setTitle(std::string const value) { this->title = value; }

		/// Author getter
		std::string getAuthor() const { return this->author; }
		/// Author setter
		void setAuthor(std::string const value) { this->author = value; }

		/// Genre getter
		std::string getGenre() const { return this->genre; }
		/// Genre setter
		void setGenre(std::string const value) { this->genre = value; }

		/// Release year getter
		int getReleaseYear() const { return this->releaseYear; }
		/// Release year setter
		void setReleaseYear(int const value) { this->releaseYear = value; }

		/// Overloading == operator
		bool operator== (const Book other) const { return this->getTitle() == other.getTitle() && this->getAuthor() == other.getAuthor(); }

		/**
		 * Validates the given data as book data
		 *
		 * @throws Exception if title, author, genre and/or releaseYear are invalid
		 */
		void ValidateData(const std::string title, const std::string author, const std::string genre, const int releaseYear) const;
};

