#pragma once
#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;
    std::string dateAdded;

public:
    Book();

    void setBookDetails(
        std::string bookTitle,
        std::string bookAuthor,
        std::string bookISBN,
        bool bookAvailable,
        std::string bookDateAdded
    );

    void displayBookDetails() const;
    bool borrowBook();
    bool returnBook();

    std::string getISBN() const;
    bool isAvailable() const;
}; 
