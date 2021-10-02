#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "../business/services.h"
#include "../infrastructure/repos.h"
#include "./graphical-interface/terminal-io.h"
#include "../domain/entities.h"

class BookstoreClient
{
	private:
		/// Book service
		BookstoreService bookstoreService = BookstoreService();

		/// Terminal input and output operations handler
		const TerminalIO io;

		/// Library service getter
		BookstoreService getBookstoreService() const { return this->bookstoreService; }
		/// Library service setter
		void setBookstoreService(BookstoreService const value) { this->bookstoreService = value; }

		/// Io getter
		TerminalIO getIO() const { return this->io; }

		/// Prints a book's data
		void PrintBook(Book const book) const;

		/// Lists all books
		void ListAllBooks() const;

		/// Adds book to the repository
		void AddBook();

		/// Modifies a book from the repository
		void ModifyBook();

		/// Deletes a book from the repository
		void DeleteBook();

		/// Searches a book in the repository
		void SearchBook();

		/// Filters books by title and/or release year
		void FilterBooks();

		/// Sorts books by title, author or release year and genre
		void SortBooks();

		/// Undoes the last basic operation
		void UndoOperation();

		/// Lists all books in the cart
		void ListAllCartBooks() const;

		/// Empties the cart
		void EmptyCart();

		/// Adds book by title to the cart
		void AddToCart();

		/// Adds random books to the cart
		void AddRandomBooksToCart();

		/// Saves the cart to csv file
		void SaveCartToFile();

		/// Lists titles from cart
		void ListAllCartTitles() const;

		/// Exits application
		void ExitApplication() const;

	public:
		/// Library client constructor
		BookstoreClient(const BookstoreService &bookstoreService);

		/// Library client destructor
		~BookstoreClient();

		/// Main application loop holder
		void RunApplication();
};

