#include <iostream>

// Import the class header files from the main application.
// Book.h allows this test application to use the Book class.
// Library.h allows this test application to use the Library class and sort function.
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
    cout << "========================================" << endl;
    cout << " Library Book System - Test Application " << endl;
    cout << "========================================" << endl << endl;

    // ------------------------------------------------------------
    // TEST 1: Correct book information initialisation
    // Purpose:
    // This test checks if the program can create and display a book
    // with complete and correct information.
    // ------------------------------------------------------------

    cout << "TEST 1: Correct book information initialisation" << endl;
    cout << "Expected result: The book should display all details correctly." << endl;
    cout << "Actual result:" << endl;

    Book correctBook;

    correctBook.setBookDetails(
        "Clean Code",
        "Robert C. Martin",
        "9780132350884",
        true,
        "01/03/2026"
    );

    correctBook.displayBookDetails();

    cout << "TEST 1 completed." << endl;
    cout << "----------------------------------------" << endl << endl;


    // ------------------------------------------------------------
    // TEST 2: Incorrect book information - empty title
    // Purpose:
    // This test checks what happens when the title field is empty.
    // ------------------------------------------------------------

    cout << "TEST 2: Incorrect book information - Empty title" << endl;
    cout << "Expected result: The program should identify that the title is missing." << endl;
    cout << "Actual result:" << endl;

    Book incorrectBook1;

    incorrectBook1.setBookDetails(
        "",
        "Robert C. Martin",
        "9780132350884",
        true,
        "01/03/2026"
    );

    incorrectBook1.displayBookDetails();

    cout << "Observation: The current program stores the book even when the title is empty." << endl;
    cout << "TEST 2 completed." << endl;
    cout << "----------------------------------------" << endl << endl;


    // ------------------------------------------------------------
    // TEST 3: Incorrect book information - empty author
    // Purpose:
    // This test checks what happens when the author field is empty.
    // ------------------------------------------------------------

    cout << "TEST 3: Incorrect book information - Empty author" << endl;
    cout << "Expected result: The program should identify that the author is missing." << endl;
    cout << "Actual result:" << endl;

    Book incorrectBook2;

    incorrectBook2.setBookDetails(
        "Clean Code",
        "",
        "9780132350884",
        true,
        "01/03/2026"
    );

    incorrectBook2.displayBookDetails();

    cout << "Observation: The current program stores the book even when the author is empty." << endl;
    cout << "TEST 3 completed." << endl;
    cout << "----------------------------------------" << endl << endl;


    // ------------------------------------------------------------
    // TEST 4: Incorrect book information - invalid ISBN
    // Purpose:
    // This test checks what happens when the ISBN contains invalid characters.
    // ------------------------------------------------------------

    cout << "TEST 4: Incorrect book information - Invalid ISBN" << endl;
    cout << "Expected result: The program should identify that the ISBN is invalid." << endl;
    cout << "Actual result:" << endl;

    Book incorrectBook3;

    incorrectBook3.setBookDetails(
        "Clean Code",
        "Robert C. Martin",
        "ABC123",
        true,
        "01/03/2026"
    );

    incorrectBook3.displayBookDetails();

    cout << "Observation: The current program stores the book even when the ISBN format is invalid." << endl;
    cout << "TEST 4 completed." << endl;
    cout << "----------------------------------------" << endl << endl;


    // ------------------------------------------------------------
    // TEST 5: Sort function implementation
    // Purpose:
    // This test checks if the Library class can initialise books
    // and run the sorting function.
    // ------------------------------------------------------------

    cout << "TEST 5: Sort function implementation" << endl;

    Library testLibrary;

    cout << "Books before sorting:" << endl;
    testLibrary.displayAllBooks();

    cout << endl;

    testLibrary.sortBookData();

    cout << "Books after sorting:" << endl;
    testLibrary.displayAllBooks();

    cout << "Expected result: Books should be displayed in ascending order by ISBN." << endl;
    cout << "TEST 5 completed." << endl;
    cout << "----------------------------------------" << endl << endl;

    cout << "All initialisation and sorting tests completed." << endl;

    return 0;
}