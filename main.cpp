#include <iostream>
#include <string>
#include "Library.h"

int main()
{
    // Create one Library object.
    // This object manages the 5 books.
    Library library;

    // This variable stores the user's menu choice.
    int option;

    // This variable stores the ISBN entered by the user.
    std::string isbn;

    // The do-while loop keeps the program running until the user enters 0.
    do
    {
        // Display the main menu.
        std::cout << "\n===== Library Book System - Phase 1 =====" << std::endl;
        std::cout << "1. Display all books" << std::endl;
        std::cout << "2. Borrow a book" << std::endl;
        std::cout << "3. Return a book" << std::endl;
        std::cout << "4. Sort books by ISBN" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your option: ";

        // Read the user's menu option.
        std::cin >> option;

        // Process the selected option.
        switch (option)
        {
        case 1:
            // Display all books.
            library.displayAllBooks();
            break;

        case 2:
            // Ask the user for an ISBN to borrow a book.
            std::cout << "Enter ISBN to borrow: ";
            std::cin >> isbn;

            // Borrow the selected book.
            library.borrowBookByISBN(isbn);
            break;

        case 3:
            // Ask the user for an ISBN to return a book.
            std::cout << "Enter ISBN to return: ";
            std::cin >> isbn;

            // Return the selected book.
            library.returnBookByISBN(isbn);
            break;

        case 4:
            // Sort the book collection by ISBN.
            library.sortBookData();
            break;

        case 0:
            // Exit the program.
            std::cout << "Exiting the program. Goodbye." << std::endl;
            break;

        default:
            // Display an error if the user enters an invalid menu option.
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }

    } while (option != 0);

    // End of program.
    return 0;
}