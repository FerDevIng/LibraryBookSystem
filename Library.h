#pragma once
#include "Book.h"
#include <string>

class Library
{
private:
    static const int MAX_BOOKS = 5;
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library();

    void initialiseBooks();
    void displayAllBooks() const;
    int findBookByISBN(std::string isbn) const;
    void borrowBookByISBN(std::string isbn);
    void returnBookByISBN(std::string isbn);
    void sortBookData();
}; #pragma once
