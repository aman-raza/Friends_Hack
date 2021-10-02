#include "./operations.h"

AddOperation::AddOperation(Book const book)
{
	// getting the added book value
	this->addedBook = book;
}

void AddOperation::UndoOperation(Repo<Book>* repo)
{
	// search the added book
	Book searchedBook = this->addedBook;
	int position = repo->FindIf(
		[&searchedBook] (Book currentBook)
		{
			return (currentBook.getTitle() == searchedBook.getTitle() && currentBook.getAuthor() == searchedBook.getAuthor());
		}
	);

	// erase the added book
	repo->Erase(position);
}

ModifyOperation::ModifyOperation(Book const oldBook, Book const newBook)
{
	// getting the modified book values (before and after)
	this->oldBook = oldBook;
	this->newBook = newBook;
}

void ModifyOperation::UndoOperation(Repo<Book>* repo)
{
	// search the modified book
	Book searchedBook = this->newBook;
	int position = repo->FindIf(
		[&searchedBook] (Book currentBook)
		{
			return (currentBook.getTitle() == searchedBook.getTitle() && currentBook.getAuthor() == searchedBook.getAuthor());
		}
	);

	// delete the changed book
	repo->Erase(position);
	// add the old book back in repo
	if (position >= repo->Size())
	{ repo->Add(this->oldBook); }
	else
	{ repo->Insert(position, this->oldBook); }
}

DeleteOperation::DeleteOperation(Book const book)
{
	// getting the added book value
	this->deletedBook = book;
}

void DeleteOperation::UndoOperation(Repo<Book>* repo)
{
	// add the deleted book back in repo
	repo->Add(this->deletedBook);
}

