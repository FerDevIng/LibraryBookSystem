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

    bool test1Result = correctBook.setBookDetails(
        "Clean Code",
        "Robert C. Martin",
        "9780132350884",
        true,
        "01/03/2026"
    );

    // If setBookDetails returns true, the valid book details were saved.
    if (test1Result)
    {
        cout << "PASS: Correct book information was accepted." << endl;
        correctBook.displayBookDetails();
    }
    else
    {
        cout << "FAIL: Correct book information was rejected." << endl;
    }

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

    bool test2Result = incorrectBook1.setBookDetails(
        "",
        "Robert C. Martin",
        "9780132350884",
        true,
        "01/03/2026"
    );

    // If setBookDetails returns false, the empty title was correctly rejected.
    if (!test2Result)
    {
        cout << "PASS: Empty title was rejected." << endl;
    }
    else
    {
        cout << "FAIL: Empty title was accepted." << endl;
        incorrectBook1.displayBookDetails();
    }

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

    bool test3Result = incorrectBook2.setBookDetails(
        "Clean Code",
        "",
        "9780132350884",
        true,
        "01/03/2026"
    );

    // If setBookDetails returns false, the empty author was correctly rejected.
    if (!test3Result)
    {
        cout << "PASS: Empty author was rejected." << endl;
    }
    else
    {
        cout << "FAIL: Empty author was accepted." << endl;
        incorrectBook2.displayBookDetails();
    }

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

    bool test4Result = incorrectBook3.setBookDetails(
        "Clean Code",
        "Robert C. Martin",
        "ABC123",
        true,
        "01/03/2026"
    );

    // If setBookDetails returns false, the invalid ISBN was correctly rejected.
    if (!test4Result)
    {
        cout << "PASS: Invalid ISBN was rejected." << endl;
    }
    else
    {
        cout << "FAIL: Invalid ISBN was accepted." << endl;
        incorrectBook3.displayBookDetails();
    }

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
