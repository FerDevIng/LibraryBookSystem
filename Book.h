#pragma once

// Include the string library because the Book class uses text values.
#include <string>

// The Book class represents one individual book in the library.
class Book
{
private:
    // Stores the title of the book.
    std::string title;

    // Stores the author of the book.
    std::string author;

    // Stores the ISBN number. This is used as the unique identifier.
    std::string isbn;

    // Stores the availability status of the book.
    // true means the book is available.
    // false means the book is already borrowed.
    bool available;

    // Stores the date when the book was added to the library.
    std::string dateAdded;

public:
    // Default constructor.
    // It creates an empty Book object with default values.
    Book();

    // This method sets all the book details.
    void setBookDetails(
        std::string bookTitle,
        std::string bookAuthor,
        std::string bookISBN,
        bool bookAvailable,
        std::string bookDateAdded
    );

    // This method displays all the details of the book.
    void displayBookDetails() const;

    // This method borrows the book if it is available.
    // It returns true if the book was borrowed successfully.
    // It returns false if the book was already borrowed.
    bool borrowBook();

    // This method returns the book if it was borrowed.
    // It returns true if the book was returned successfully.
    // It returns false if the book was already available.
    bool returnBook();

    // This method returns the ISBN of the book.
    // It is used when searching for a book.
    std::string getISBN() const;

    // This method returns the current availability status.
    bool isAvailable() const;
};
