#include "Book.h"
#include <iostream>

Book::Book()
{
    title = "";
    author = "";
    isbn = "";
    available = true;
    dateAdded = "";
}

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

void Book::displayBookDetails() const
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Date Added: " << dateAdded << std::endl;
    std::cout << "Availability: " << (available ? "Available" : "Borrowed") << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

bool Book::borrowBook()
{
    if (available)
    {
        available = false;
        return true;
    }

    return false;
}

bool Book::returnBook()
{
    if (!available)
    {
        available = true;
        return true;
    }

    return false;
}

std::string Book::getISBN() const
{
    return isbn;
}

bool Book::isAvailable() const
{
    return available;
}