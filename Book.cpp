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
// It checks the title, author, and ISBN before saving the details.
bool Book::setBookDetails(
    std::string bookTitle,
    std::string bookAuthor,
    std::string bookISBN,
    bool bookAvailable,
    std::string bookDateAdded
)
{
    // Do not save the details if the title is empty.
    if (bookTitle.empty())
    {
        return false;
    }

    // Do not save the details if the author is empty.
    if (bookAuthor.empty())
    {
        return false;
    }

    // Do not save the details if the ISBN is empty or has the wrong format.
    if (!isValidISBN(bookISBN))
    {
        return false;
    }

    // The details are valid, so they can now be saved.
    title = bookTitle;
    author = bookAuthor;
    isbn = bookISBN;
    available = bookAvailable;
    dateAdded = bookDateAdded;

    return true;
}

// This helper method checks that the ISBN contains only numbers
// and is either 10 or 13 digits long.
bool Book::isValidISBN(std::string bookISBN) const
{
    // ISBN cannot be empty.
    if (bookISBN.empty())
    {
        return false;
    }

    // ISBN must be either 10 or 13 digits long.
    if (bookISBN.length() != 10 && bookISBN.length() != 13)
    {
        return false;
    }

    // Check each character to make sure it is a number.
    for (int i = 0; i < bookISBN.length(); i++)
    {
        if (bookISBN[i] < '0' || bookISBN[i] > '9')
        {
            return false;
        }
    }

    return true;
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
