// ===============================================================
// BstTest.cpp
//       Comprehensive testing of Template BST class with
//       Function Pointers
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Lab 10
// ===============================================================

#include "Bst.h"
#include "Date.h"
#include "Utilities.h"
#include "Vector.h"
#include "CollectU.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Print callback for Test 2
void SimplePrint(const Date& d)
{
    cout << d << " ";
}

int main()
{
    // Initialise test counters and CollectU
    int passCount = 0;
    int failCount = 0;
    CollectU collector;

    cout << "==== Running BST Function Pointer Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Basic Insertion and InOrder logic --------
    cout << "--- Test 1 (BST Invariant and Manual Search) ---" << endl;
    Bst<Date> tree;
    Date d1(10,5,2025);
    Date d2(22,12,2025);
    Date d3(13,8,2025);

    tree.Insert(d1);
    tree.Insert(d2);
    tree.Insert(d3);

    AssertEqual("BST Invariant is valid", tree.IsValid(), passCount, failCount);
    AssertEqual("Search for existing date", tree.Search(d2), passCount, failCount);
    cout << endl;

    // -------- TEST 2: Function Pointer Traversal (Printing) --------
    cout << "--- Test 2 (Function Pointer: Simple Print) ---" << endl;
    cout << "Expected: 10 May 2025 22 December 2025 13 August 2025" << endl;
    cout << "Actual: ";
    tree.InOrder(SimplePrint);
    cout << endl << "Verify visually above." << endl << endl;

    // -------- TEST 3: Data Collection --------
    cout << "--- Test 3 (Data collection via Static Callback) ---" << endl;
    collector.clear();

    tree.InOrder(CollectU::Collect);

    AssertEqual("Collector size is 3", collector.size() == 3, passCount, failCount);
    AssertEqual("First collected element is smallest (InOrder)",
                collector[0] == d1, passCount, failCount);
    AssertEqual("Last collected element is largest (InOrder)",
                collector[2] == d2, passCount, failCount);

    cout << endl;

    // -------- TEST 4: Deep Copy (Pass by Value) --------
    cout << "--- Test 4 (Pass by Value/Copy Constructor) ---" << endl;

    Bst<Date> copyTree = tree;
    AssertEqual("Copy Tree is valid", copyTree.IsValid(), passCount, failCount);
    AssertEqual("Copy Tree contains original data", copyTree.Search(d1), passCount, failCount);

    copyTree.Insert(Date(1,1,2026));
    AssertEqual("Original tree remains unchanged", tree.Search(Date(1,1,2026)) == false, passCount, failCount);

    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ===" << endl;
    cout << "Total Passed : " << passCount << endl;
    cout << "Total Failed : " << failCount << endl;
    cout << "       Total : " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of BST Function Pointer Test Cases ====" << endl;


    return 0;
}
