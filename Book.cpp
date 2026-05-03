#include "Book.h"
#include <iostream>

// Default constructor.
// This gives safe default values when a Book object is created.
Book::Book()
{
    title = "";
    author = "";
    isbn = "";
    available = true;
    dateAdded = "";
}

// This method assigns values to the book attributes.
void Book::setBookDetails(
    std::string bookTitle,
    std::string bookAuthor,
    std::string bookISBN,
    bool bookAvailable,
    std::string bookDateAdded
)
{
    title = bookTitle;
    author = bookAuthor;
    isbn = bookISBN;
    available = bookAvailable;
    dateAdded = bookDateAdded;
}

// This method displays the book details in the console.
void Book::displayBookDetails() const
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Date Added: " << dateAdded << std::endl;

    // This line displays Available if available is true.
    // Otherwise, it displays Borrowed.
    std::cout << "Availability: " << (available ? "Available" : "Borrowed") << std::endl;

    std::cout << "-----------------------------------" << std::endl;
}

// This method changes the book status to borrowed.
bool Book::borrowBook()
{
    // Check if the book is available.
    if (available)
    {
        // Mark the book as borrowed.
        available = false;

        // Return true because the borrow action was successful.
        return true;
    }

    // Return false because the book was not available.
    return false;
}

// This method changes the book status back to available.
bool Book::returnBook()
{
    // Check if the book is currently borrowed.
    if (!available)
    {
        // Mark the book as available again.
        available = true;

        // Return true because the return action was successful.
        return true;
    }

    // Return false because the book was already available.
    return false;
}

// This method returns the ISBN.
// It helps the Library class search for a book.
std::string Book::getISBN() const
{
    return isbn;
}

// This method returns the availability status.
bool Book::isAvailable() const
{
    return available;
}