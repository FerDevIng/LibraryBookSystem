#include "Library.h"
#include <iostream>

// Constructor for the Library class.
Library::Library()
{
    // In Phase 1, the library manages exactly 5 books.
    bookCount = MAX_BOOKS;

    // Load the predefined book data.
    initialiseBooks();
}

// This method creates the initial 5 books for the library.
void Library::initialiseBooks()
{
    books[0].setBookDetails("Clean Code", "Robert C. Martin", "9780132350884", true, "01/03/2026");
    books[1].setBookDetails("The Pragmatic Programmer", "Andrew Hunt", "9780201616224", true, "05/03/2026");
    books[2].setBookDetails("Design Patterns", "Erich Gamma", "9780201633610", true, "10/03/2026");
    books[3].setBookDetails("Introduction to Algorithms", "Thomas H. Cormen", "9780262033848", true, "15/03/2026");
    books[4].setBookDetails("C++ Primer", "Stanley B. Lippman", "9780321714114", true, "20/03/2026");
}

// This method displays all books stored in the array.
void Library::displayAllBooks() const
{
    std::cout << "\n===== Library Book List =====" << std::endl;

    // Loop through the array and display each book.
    for (int i = 0; i < bookCount; i++)
    {
        books[i].displayBookDetails();
    }
}

// This method searches for a book by ISBN.
int Library::findBookByISBN(std::string isbn) const
{
    // Check each book in the array.
    for (int i = 0; i < bookCount; i++)
    {
        // Compare the current book ISBN with the ISBN entered by the user.
        if (books[i].getISBN() == isbn)
        {
            // Return the position of the book if it is found.
            return i;
        }
    }

    // Return -1 if no book matches the ISBN.
    return -1;
}

// This method borrows a book using the ISBN entered by the user.
void Library::borrowBookByISBN(std::string isbn)
{
    // Search for the book first.
    int index = findBookByISBN(isbn);

    // If index is -1, the book was not found.
    if (index == -1)
    {
        std::cout << "Error: Book with ISBN " << isbn << " was not found." << std::endl;
        return;
    }

    // Try to borrow the book.
    if (books[index].borrowBook())
    {
        std::cout << "Book borrowed successfully." << std::endl;
    }
    else
    {
        std::cout << "Error: This book is already borrowed and is not available." << std::endl;
    }
}

// This method returns a book using the ISBN entered by the user.
void Library::returnBookByISBN(std::string isbn)
{
    // Search for the book first.
    int index = findBookByISBN(isbn);

    // If index is -1, the book was not found.
    if (index == -1)
    {
        std::cout << "Error: Book with ISBN " << isbn << " was not found." << std::endl;
        return;
    }

    // Try to return the book.
    if (books[index].returnBook())
    {
        std::cout << "Book returned successfully." << std::endl;
    }
    else
    {
        std::cout << "Error: This book is already available and cannot be returned again." << std::endl;
    }
}

// This method sorts the book array by ISBN.
// A simple Bubble Sort is used because Phase 1 only has 5 books.
void Library::sortBookData()
{
    // Outer loop controls the number of passes.
    for (int i = 0; i < bookCount - 1; i++)
    {
        // Inner loop compares two neighbouring books.
        for (int j = 0; j < bookCount - i - 1; j++)
        {
            // If the current ISBN is greater than the next ISBN, swap the books.
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