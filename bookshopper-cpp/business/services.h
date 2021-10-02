#pragma once

#include <algorithm>
#include <fstream>
#include <memory>
#include <random>
#include <stack>
#include <string>
#include <vector>

#include "../domain/entities.h"
#include "../domain/exceptions.h"
#include "../domain/operations.h"
#include "../infrastructure/repos.h"

class Operation;

class BookstoreService
{
	private:
		/// The books repository
		std::shared_ptr<Repo<Book>> booksRepo;

		/// The shopping cart repository
		std::shared_ptr<Repo<Book>> cart;

		/// Operations history
		std::stack<std::shared_ptr<Operation>> operationsHistory = std::stack<std::shared_ptr<Operation>>();

	public:
		/// Library service constructor
		BookstoreService(std::shared_ptr<Repo<Book>> const &booksRepo = std::make_shared<DictRepo<Book>>(), std::shared_ptr<Repo<Book>> const &cart = std::make_shared<DictRepo<Book>>());

		/// Library service destructor
		~BookstoreService();

		/// Books repository getter
		std::shared_ptr<Repo<Book>> getBooksRepo() const 
		{
			// making a copy of the repo and returning it
			std::shared_ptr<Repo<Book>> repoCopy = std::make_shared<DictRepo<Book>>();
			repoCopy->setElements(this->booksRepo->getElements());
			return repoCopy;
		}
		/// Books repository setter
		void setBooksRepo(std::shared_ptr<Repo<Book>> const &value) { this->booksRepo = value; }

		/// Shopping cart getter
		std::shared_ptr<Repo<Book>> getCart() const 
		{
			// making a copy of the cart and returning it
			std::shared_ptr<Repo<Book>> cartCopy = std::make_shared<DictRepo<Book>>();
			cartCopy->setElements(this->cart->getElements());
			return cartCopy;
		}

		/// Shopping cart setter
		void setCart(std::shared_ptr<Repo<Book>> const &value) { this->cart = value; }

		/**
		 * Gets all books from the repo
		 *
		 * @throws Exception if empty repo
		 */
		std::vector<Book> GetBooks() const;

		/**
		 * Adds a book to the repo
		 *
		 * @param title The title of the book
		 * @param author The author of the book
		 * @param genre The genre of the book
		 * @param releaseYear The release year of the book
		 * @throws Exception if book invalid or is duplicate
		 */
		void AddBookToRepo(const std::string &title = "", const std::string &author = "", const std::string &genre = "", const int &releaseYear = 0);

		/**
		 * Modifies a book from the repo, searching by title and author
		 *
		 * @param titleSearch The title to search by
		 * @param authorSearch The author to search by
		 * @param title The new title of the book
		 * @param author The new author of the book
		 * @param genre The new genre of the book
		 * @param releaseYear The new release year of the book
		 * @throws Exception if the repo is empty, if the search fields are invalid, if the new book is invalid, if it becomes duplicated after the modification or if book was not found
		 */
		void ModifyBookInRepo(const std::string &titleSearch, const std::string &authorSearch, const std::string &title = "", const std::string &author = "", const std::string &genre = "", const int &releaseYear = 0);

		/**
		 * Deletes a book from the repo, searching by title and author
		 *
		 * @param titleSearch The title to search by
		 * @param authorSearch The author to search by
		 * @throws Exception if the repo is empty, if the search fields are invalid or if book was not found
		 */
		void DeleteBookFromRepo(const std::string &titleSearch, const std::string &authorSearch);

		/**
		 * Searches a book in the repo by title, author, genre and/or release year
		 *
		 * @param titleSearch The title to search by
		 * @param authorSearch The author to search by
		 * @param genreSearch The genre to search by
		 * @param releaseYearSearch The release year to search by
		 * @returns The first book match from the repo
		 * @throws Exception if empty repo, if no fields valid or book not found
		 */
		Book SearchBook(const std::string &titleSearch, const std::string &authorSearch, const std::string &genreSearch, const int &releaseYearSearch) const;

		/**
		 * Gets books from the repo, filtered by title
		 *
		 * @param titleFilter The title to filter with
		 * @returns The books repo, filtered by title
		 * @throws Exception if there are no books in repo, if filter is invalid or no books remain after filtering
		 */
		std::vector<Book> GetFilteredBooks(const std::string &titleFilter) const;

		/**
		 * Gets books from the repo, filtered by release year
		 *
		 * @param releaseYearFilter The release year to filter with
		 * @returns The books repo, filtered by release year
		 * @throws Exception if there are no books in repo, if filter is invalid or no books remain after filtering
		 */
		std::vector<Book> GetFilteredBooks(const int &releaseYearFilter) const;

		/// Sorts the books repo by title
		void SortBooksByTitle();

		/// Sorts the books repo by author
		void SortBooksByAuthor();

		/// Sorts the books repo by release year and genre
		void SortBooksByReleaseYearAndGenre();

		/**
		 * Undoes the last basic operation
		 *
		 * @throws Exception if already at oldest change
		 */
		void UndoOperation();

		/**
		 * Gets all books from the cart
		 *
		 * @returns All books from cart
		 * @throws Exception if empty cart
		 */
		std::vector<Book> GetCartBooks() const;

		/// Empties the cart
		void EmptyCart();

		/**
		 * Adds a book from the repo to the cart, by title
		 *
		 * @param title The title of the book to be added
		 * @throws Exception if book not found, title is invalid or repo is empty
		 */
		void AddToCart(const std::string &title);

		/**
		 * Adds random books to the cart
		 *
		 * @param count The number of books to randomly be added
		 * @throws Exception if count is not valid or repo is empty
		 */
		void AddRandomBooksToCart(const int &count);

		/**
		 * Saves the shopping cart to cvs file
		 *
		 * @param fileName The name of the file
		 * @throws Exception if repo is empty
		 */
		void SaveCartToFile(const std::string &fileName) const;

		/**
		 * Gets all books' titles from the cart
		 *
		 * @returns All books' titles from cart
		 */
		std::vector<std::string> GetCartTitles() const;
};

