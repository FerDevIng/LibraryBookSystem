#include <iostream>

// These header files import the class definitions from the main application.
// Book.h allows this test file to create and test Book objects.
// Library.h allows this test file to create and test the Library object and sorting function.
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
    // Display the title of the test application.
    cout << "========================================" << endl;
    cout << " Library Book System - Test Application " << endl;
    cout << "========================================" << endl << endl;

    // ------------------------------------------------------------
    // TEST 1: Test the Book class implementation
    // Purpose:
    // This test creates one Book object and displays its details.
    // This proves that the Book class implementation can be imported
    // and used inside the test application.
    // ------------------------------------------------------------

    cout << "TEST 1: Book class implementation" << endl;
    cout << "Expected result: The book details should display correctly." << endl;
    cout << "Actual result:" << endl;

    // Create a Book object using the default constructor.
    Book testBook;

    // Add correct book information using the setBookDetails method.
    testBook.setBookDetails(
        "Clean Code",
        "Robert C. Martin",
        "9780132350884",
        true,
        "01/03/2026"
    );

    // Display the book details to check if the data was saved correctly.
    testBook.displayBookDetails();

    cout << "TEST 1 completed." << endl;
    cout << "----------------------------------------" << endl << endl;


    // ------------------------------------------------------------
    // TEST 2: Test the Library class implementation
    // Purpose:
    // This test creates a Library object and displays all books.
    // This proves that the Library class implementation can be imported
    // and used inside the test application.
    // ------------------------------------------------------------

    cout << "TEST 2: Library class implementation" << endl;
    cout << "Expected result: The five predefined books should display." << endl;
    cout << "Actual result:" << endl;

    // Create a Library object.
    // The constructor automatically calls initialiseBooks().
    Library testLibrary;

    // Display all books stored in the library.
    testLibrary.displayAllBooks();

    cout << "TEST 2 completed." << endl;
    cout << "----------------------------------------" << endl << endl;


    // ------------------------------------------------------------
    // TEST 3: Test the sort function implementation
    // Purpose:
    // This test calls the sortBookData() method from the Library class.
    // This proves that the sort function implementation can be imported
    // and executed from the test application.
    // ------------------------------------------------------------

    cout << "TEST 3: Sort function implementation" << endl;

    cout << "Books before sorting:" << endl;
    testLibrary.displayAllBooks();

    cout << endl;

    // Call the sorting function from the Library class.
    testLibrary.sortBookData();

    cout << endl;
    cout << "Books after sorting by ISBN:" << endl;
    testLibrary.displayAllBooks();

    cout << "Expected result: The books should be organised in ascending ISBN order." << endl;
    cout << "TEST 3 completed." << endl;
    cout << "----------------------------------------" << endl << endl;


    // End of the test application.
    cout << "All Requirement 1 tests completed." << endl;

    return 0;
}