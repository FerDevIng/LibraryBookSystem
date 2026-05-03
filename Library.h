#pragma once

// Include the Book class because Library uses Book objects.
#include "Book.h"

// Include string because ISBN values are stored as text.
#include <string>

// The Library class manages the collection of books.
class Library
{
private:
    // Maximum number of books for Phase 1.
    static const int MAX_BOOKS = 5;

    // Fixed array that stores 5 Book objects.
    Book books[MAX_BOOKS];

    // Stores how many books are currently managed by the library.
    int bookCount;

public:
    // Constructor.
    // It creates the library and initialises the book collection.
    Library();

    // This method adds the five predefined books to the array.
    void initialiseBooks();

    // This method displays all books in the library.
    void displayAllBooks() const;

    // This method searches for a book by ISBN.
    // It returns the index position if the book is found.
    // It returns -1 if the book is not found.
    int findBookByISBN(std::string isbn) const;

    // This method borrows a book using its ISBN.
    void borrowBookByISBN(std::string isbn);

    // This method returns a book using its ISBN.
    void returnBookByISBN(std::string isbn);

    // This method sorts the books by ISBN.
    void sortBookData();
};