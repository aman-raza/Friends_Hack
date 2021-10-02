#include <iostream>
#include <memory>
#include <vector>

#include "./business/services.h"
#include "./domain/entities.h"
#include "./infrastructure/repos.h"
#include "./interface/clients.h"

auto main() -> int
{
	// the books repository
	std::shared_ptr<Repo<Book>> booksRepo = std::make_shared<DictRepo<Book>>();
	// the shopping cart
	std::shared_ptr<DictRepo<Book>> cart = std::make_shared<DictRepo<Book>>();
	// the bookshop service
	BookstoreService bookstoreService = BookstoreService(booksRepo, cart);
	// the bookshop client
	BookstoreClient bookstoreClient = BookstoreClient(bookstoreService);

	// start the application
	bookstoreClient.RunApplication();
	return 0;
}

