// ===============================================================
// VectorTest.cpp
//      Comprehensive testing of Vector template class
//      Test constructors, insert operations, access methods,
//      and size management
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#include "Vector.h"
#include "Utilities.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    // Initialise test counters
    int passCount = 0;
    int failCount = 0;

    cout << "==== Running Vector Test Cases ===" << endl
         << endl;

    // -------- TEST 1: Default Constructor --------
    // Verify that default constructor initialises empty vector
    cout << "--- Test 1: Default Constructor ---" << endl;
    Vector<int> numbers;
    cout << "Constructed Default Vector object: numbers" << endl
         << endl;
    AssertEqual("Vector size is 0", numbers.Size() == 0, passCount, failCount);
    cout << endl;

    // -------- TEST 2: Insert Integer Elements --------
    // Verify that insert correctly adds elements to vector
    cout << "--- Test 2: Insert Integer Elements ---" << endl;
    numbers.Insert(99, 0);
    AssertEqual("Size after first insert is 1", numbers.Size() == 1, passCount, failCount);
    AssertEqual("First element is 99", numbers[0] == 99, passCount, failCount);

    numbers.Insert(88, 1);
    AssertEqual("Size after second insert is 2", numbers.Size() == 2, passCount, failCount);
    AssertEqual("Second element is 88", numbers[1] == 88, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Vector with String Elements --------
    // Verify that vector works with string template
    cout << "--- Test 3: Vector with String Elements ---" << endl;
    Vector<string> names;
    cout << "Constructed Vector<string> object: names" << endl
         << endl;
    AssertEqual("Vector size is 0", names.Size() == 0, passCount, failCount);

    names.Insert("June", 0);
    AssertEqual("Size after insert is 1", names.Size() == 1, passCount, failCount);
    AssertEqual("First element is June", names[0] == "June", passCount, failCount);

    names.Insert("July", 1);
    AssertEqual("Size after second insert is 2", names.Size() == 2, passCount, failCount);
    AssertEqual("Second element is July", names[1] == "July", passCount, failCount);
    cout << endl;

    // -------- TEST SUMMARY --------
    cout << "==== Test Summary ====" << endl;
    cout << "Passed: " << passCount << endl;
    cout << "Failed: " << failCount << endl;
    cout << "Total: " << (passCount + failCount) << endl;

    cout << "==== End of Vector Test Cases ====" << endl;

    return 0;
}
