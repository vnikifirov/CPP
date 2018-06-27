#pragma once

#include <iostream>
#include <string>

class Books
{
public:
	// Default Constructor
	Books();

	// Overload Constructor
	Books(std::string, unsigned int);

	// ~Destructor
	~Books();

	//Accessor Functions
	std::string getBook() const;
		// getBook
		// @pragma return string - name of books

	unsigned int getRatings() const;
		// getRatings
		// @pragma return unsigned int - value of ratings

	//Mutator Functions
	void setBook(std::string);
		// setBook
		// @pragma string - name of books

	void setRating(unsigned int);
		// setRating
		// @pragma unsigned int - value of ratings

private:
	// Members Functions
	std::string books;
	unsigned int ratings;
};

Books::Books()
{
	books = ' ';
	ratings = 0;
}

Books::Books(std::string books, unsigned int ratings)
{
	this->books = books;
	this->ratings = ratings;
}

Books::~Books() {}

std::string Books::getBook() const
{
	return books;
}

unsigned int Books::getRatings() const
{
	return ratings;
}

void Books::setBook(std::string books)
{
	this->books = books;
}

void Books::setRating(unsigned int ratings)
{
	this->ratings = ratings;
}