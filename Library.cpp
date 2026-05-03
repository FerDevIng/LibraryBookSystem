#include "Library.h"
#include <iostream>

Library::Library()
{
    bookCount = MAX_BOOKS;
    initialiseBooks();
}

void Library::initialiseBooks()
{
    books[0].setBookDetails("Clean Code", "Robert C. Martin", "9780132350884", true, "01/03/2026");
    books[1].setBookDetails("The Pragmatic Programmer", "Andrew Hunt", "9780201616224", true, "05/03/2026");
    books[2].setBookDetails("Design Patterns", "Erich Gamma", "9780201633610", true, "10/03/2026");
    books[3].setBookDetails("Introduction to Algorithms", "Thomas H. Cormen", "9780262033848", true, "15/03/2026");
    books[4].setBookDetails("C++ Primer", "Stanley B. Lippman", "9780321714114", true, "20/03/2026");
}

void Library::displayAllBooks() const
{
    std::cout << "\n===== Library Book List =====" << std::endl;

    for (int i = 0; i < bookCount; i++)
    {
        books[i].displayBookDetails();
    }
}

int Library::findBookByISBN(std::string isbn) const
{
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getISBN() == isbn)
        {
            return i;
        }
    }

    return -1;
}

void Library::borrowBookByISBN(std::string isbn)
{
    int index = findBookByISBN(isbn);

    if (index == -1)
    {
        std::cout << "Error: Book with ISBN " << isbn << " was not found." << std::endl;
        return;
    }

    if (books[index].borrowBook())
    {
        std::cout << "Book borrowed successfully." << std::endl;
    }
    else
    {
        std::cout << "Error: This book is already borrowed and is not available." << std::endl;
    }
}

void Library::returnBookByISBN(std::string isbn)
{
    int index = findBookByISBN(isbn);

    if (index == -1)
    {
        std::cout << "Error: Book with ISBN " << isbn << " was not found." << std::endl;
        return;
    }

    if (books[index].returnBook())
    {
        std::cout << "Book returned successfully." << std::endl;
    }
    else
    {
        std::cout << "Error: This book is already available and cannot be returned again." << std::endl;
    }
}

void Library::sortBookData()
{
    for (int i = 0; i < bookCount - 1; i++)
    {
        for (int j = 0; j < bookCount - i - 1; j++)
        {
            if (books[j].getISBN() > books[j + 1].getISBN())
            {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    std::cout << "Book data sorted by ISBN successfully." << std::endl;
}