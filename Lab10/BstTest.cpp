// ===============================================================
// BstTest.cpp
//       Comprehensive testing of Template BST class
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
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

// Print callback for Printing
void SimplePrint(const Date& d)
{
    cout << d << " ";
}

// Helper to test Pass-by-Value
void TestPassByValue(Bst<Date> tempTree, const Date& checkDate, int& pass, int& fail)
{
    AssertEqual("Pass-by-value: Tree remains valid", tempTree.IsValid(), pass, fail);
    AssertEqual("Pass-by-value: Tree contains data", tempTree.Search(checkDate), pass, fail);
}

Vector<Date> testDateStorage;

void CollectDate(const Date& date)
{
    testDateStorage.Add(date);
}

int main()
{
    // Initialise test counters and CollectU
    int passCount = 0;
    int failCount = 0;
    CollectU collector;

    cout << "==== Running BST Test Cases ====" << endl
         << endl;

    // -------- TEST 1: Basic Insertion and Invariant --------
    cout << "--- Test 1: Insertion & Invariant ---" << endl;
    Bst<Date> tree;
    Date dRoot(15, 5, 2020);
    Date dLeft(10, 5, 2020);
    Date dRight(20, 5, 2020);

    tree.Insert(dRoot);
    tree.Insert(dLeft);
    tree.Insert(dRight);

    AssertEqual("BST Invariant is valid", tree.IsValid(), passCount, failCount);
    cout << endl;

    // -------- TEST 2: Search Logic --------
    cout << "--- Test 2: Search Logic ---" << endl;
    Date missingDate(1, 1, 1999);
    AssertEqual("Search: Found existing element", tree.Search(dLeft), passCount, failCount);
    AssertEqual("Search: Correctly missed non-existent element", tree.Search(missingDate) == false, passCount, failCount);
    cout << endl;

    // -------- TEST 3: Multiple Traversals (Function Pointers) --------
    cout << "--- Test 3: Traversals: In, Pre, Post ---" << endl;
    cout << "InOrder (Expected: 10/05/2020 15/05/2020 20/05/2020): " << endl << "   Actual: ";
    tree.InOrder(SimplePrint);

    cout << endl << "PreOrder (Expected: 15/05/2020 10/05/2020 20/05/2020): " << endl << "   Actual: ";
    tree.PreOrder(SimplePrint);

    cout << endl << "PostOrder (Expected: 10/05/2020 20/05/2020 15/05/2020): " << endl << "   Actual: ";
    tree.PostOrder(SimplePrint);
    cout << endl << endl;

    // -------- TEST 4: Data Collection via Static Callback --------
    cout << "--- Test 4: CollectU collection via static callback ---" << endl;
    testDateStorage.Clear();
    tree.InOrder(CollectDate);

    AssertEqual("Collector size matches tree size", testDateStorage.Size() == 3, passCount, failCount);
    AssertEqual("First element is correctly sorted", testDateStorage[0] == dLeft, passCount, failCount);
    cout << endl;

    // -------- TEST 5: Deep Copy & Pass-by-Value --------
    cout << "--- Test 5: Deep Copy Constructor & Scope ---" << endl;
    TestPassByValue(tree, dRoot, passCount, failCount);

    Bst<Date> copyTree = tree;
    copyTree.Insert(Date(30, 5, 2020));

    AssertEqual("Original tree size remains 3", tree.Search(Date(30,5,2020)) == false, passCount, failCount);
    AssertEqual("Copy tree contains new element", copyTree.Search(Date(30,5,2020)), passCount, failCount);
    cout << endl;

    // -------- TEST 6: Assignment Operator --------
    cout << "--- Test 6: Assignment Operator ---" << endl;
    Bst<Date> assignedTree;
    assignedTree = tree;
    AssertEqual("Assigned tree is valid", assignedTree.IsValid(), passCount, failCount);
    AssertEqual("Assigned tree has same data", assignedTree.Search(dRight), passCount, failCount);
    cout << endl;

    // -------- Summary --------
    cout << "==== Test Results Summary ===" << endl;
    cout << "Total Passed : " << passCount << endl;
    cout << "Total Failed : " << failCount << endl;
    cout << "       Total : " << (passCount + failCount) << endl
         << endl;

    cout << "==== End of BST Test Cases ====" << endl;


    return 0;
}
