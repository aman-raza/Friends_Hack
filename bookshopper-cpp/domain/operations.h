#pragma once

#include <memory>

#include "./entities.h"
#include "../infrastructure/repos.h"

/// Base operation object
class Operation
{
	public:
		/// Operation constructor 
		Operation() = default;

		/// Undoes an operation
		virtual void UndoOperation(Repo<Book>* repo) = 0;
};

/// Adding operation object
class AddOperation: public Operation
{
	protected:
		/// The added book
		Book addedBook;

	public:
		/// AddOperation constructor
		AddOperation(Book const book);

		/// Undoes the adding book operation
		void UndoOperation(Repo<Book>* repo) override;
};

/// Modifying operation object
class ModifyOperation: public Operation
{
	protected:
		/// The old and new book
		Book oldBook, newBook;

	public:
		/// ModifyOperation constructor
		ModifyOperation(Book const oldBook, Book const newBook);

		/// Undoes the modifying book operation
		void UndoOperation(Repo<Book>* repo) override;
};

/// Deleting operation object
class DeleteOperation: public Operation
{
	protected:
		/// The deleted book
		Book deletedBook;

	public:
		/// DeleteOperation constructor
		DeleteOperation(Book const book);

		/// Undoes the deleting book operation
		void UndoOperation(Repo<Book>* repo) override;
};

