#include <iostream>
#include <fstream>

#include "Bst.h"
#include "Date.h"
#include "Utilities.h"
#include "CSVLoader.h"
#include "Vector.h"
#include "Math.h"

using namespace std;

// Helper function declarations
void printByReference(const Bst<Date>& tree);
void printByValue(Bst<Date> tree);
void LoadDateTree(Bst<Date>& dateTree);
void PrintDate(const Date& d);

void PrintDate(const Date& d) {
        cout << "Date: " << d << endl;
    }
// Test function: Print tree by const reference
// Purpose: Demonstrate passing object by const reference (no copying)
/*void printByReference(const Bst<Date>& tree)
{
    cout << "Tree passed by reference (InOrder): ";
    tree.InOrder();
}*/

// Test function: Print tree by value
// Purpose: Demonstrate passing object by value (invokes copy constructor)
/*void printByValue(Bst<Date> tree)
{
    cout << "Tree passed by value (PreOrder): ";
    tree.PreOrder();
}*/

// Load all dates from CSV data files into the BST
// Purpose: Populate the date tree with all unique dates from weather records
void LoadDateTree(Bst<Date>& dateTree)
{
    // Create CSV loader to read all data files
    CSVLoader loader;

    // Load all weather records from CSV files
    WeatherRecordCollection data = loader.LoadAllCSV();

    // Insert each unique date from the records into the BST
    for(int i = 0; i < data.Size(); i++)
    {
        WeatherRecord record = data[i];
        dateTree.Insert(record.GetDate());
    }
}

int main()
{
    // Create a binary search tree to store Date objects
    Bst<Date> dateTree;

    // Load all date values from CSV data files into the tree
    LoadDateTree(dateTree);

    // Test 1: Validate BST invariant property
    cout << "BST invariant check: ";
    if(dateTree.IsValid())
    {
        cout << "Valid BST" << endl;
    }
    else
    {
        cout << "Invalid BST" << endl;
    }
    cout << endl;

    // Test 2: Display tree using different traversal methods
    /*cout << "InOrder Traversal: ";
    dateTree.InOrder();
    cout << endl;

    cout << "PreOrder Traversal: ";
    dateTree.PreOrder();
    cout << endl;

    cout << "PostOrder Traversal: ";
    dateTree.PostOrder();
    cout << endl;*/

    // Test 3: Search for a specific date
    Date searchDate(22, 12, 2011);
    cout << "Search 22/12/2011: ";
    if(dateTree.Search(searchDate))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    cout << endl;

    // Test 4: Test pass by const reference (no copy made)
    //printByReference(dateTree);
    //cout << endl;

    // Test 5: Test pass by value (invokes copy constructor)
    //printByValue(dateTree);
    //cout << endl;

    // --- Testing sPCC ---
    Vector<double> v1;
    Vector<double> v2;
    Vector<double> v3;

    // Data Set 1: 1, 2, 3, 4, 5
    // Data Set 2: 10, 20, 30, 40, 50 (Perfect Positive Correlation with v1)
    // Data Set 3: 50, 40, 30, 20, 10 (Perfect Negative Correlation with v1)

    for(int i = 1; i <= 5; i++) {
        v1.Add(i);
        v2.Add(i * 10);
        v3.Add(60 - (i * 10));
    }

    cout << "--- Testing sPCC ---" << endl;
    Math math;

    // Test 1: Perfect Positive Correlation
    double result1 = math.CalculateSPCC(v1, v2);
    cout << "Test 1 (Positive): " << result1
              << (result1 > 0.99 ? " [PASS]" : " [FAIL]") << endl;

    // Test 2: Perfect Negative Correlation
    double result2 = math.CalculateSPCC(v1, v3);
    cout << "Test 2 (Negative): " << result2
              << (result2 < -0.99 ? " [PASS]" : " [FAIL]") << endl;

    // Test 3: Size Mismatch
    v3.Add(100.0); // Make v3 larger than v1
    double result3 = math.CalculateSPCC(v1, v3);
    cout << "Test 3 (Mismatch): " << result3
              << (result3 == 0.0 ? " [PASS]" : " [FAIL]") << endl;

    // --- Testing MAD ---
    Vector<double> vMAD;
    vMAD.Add(10.0);
    vMAD.Add(20.0);
    vMAD.Add(30.0);

    double resultMAD = math.CalculateMAD(vMAD);

    cout << "\n--- Testing MAD ---" << endl;
    cout << "Data: {10, 20, 30}, Mean: 20" << endl;
    cout << "Expected MAD: ~6.66" << endl;
    cout << "Result MAD: " << resultMAD << endl;

    if(resultMAD > 6.6 && resultMAD < 6.7) {
        cout << "Test MAD: [PASS]" << endl;
    } else {
        cout << "Test MAD: [FAIL] - Check if you forgot absolute values!" << endl;
    }

    // Testing pointer fucntion
    // 1. Create a "callback" function that matches the signature
    cout << "Traversing tree using function pointer:" << endl;

    // 2. Pass the function NAME as the argument
    dateTree.InOrder(PrintDate);

    return 0;
}
