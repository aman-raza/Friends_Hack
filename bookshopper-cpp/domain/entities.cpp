#include "./entities.h"

Book::Book(std::string title, std::string author, std::string genre, int releaseYear)
{
	this->ValidateData(title, author, genre, releaseYear);
	// setting fields of Book instance to parameter values
	this->setTitle(title);
	this->setAuthor(author);
	this->setGenre(genre);
	this->setReleaseYear(releaseYear);
}

Book::~Book()
{
	// setting fields of Book instance to default values
	this->setTitle("");
	this->setAuthor("");
	this->setGenre("");
	this->setReleaseYear(0);
}

void Book::ValidateData(const std::string title, const std::string author, const std::string genre, const int releaseYear) const
{
	// initializing exception string
	std::string message = "";
	// exception if title is empty
	if (title.empty())
	{ message += "invalid title\n"; }
	// exception if author is empty
	if (author.empty())
	{ message += "invalid author\n"; }
	// exception if genre is empty
	if (genre.empty())
	{ message += "invalid genre\n"; }
	// exception if release year is negative
	if (releaseYear < 0)
	{ message += "invalid release year\n"; }
	
	// throw exception if any data is invalid
	if (!message.empty())
	{ throw ValidationError(message); }
}

