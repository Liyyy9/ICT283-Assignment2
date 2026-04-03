// ===============================================================
// Bst.h
//      Template Binary Search Tree (BST) class
//      Provides ordered storage, search, and traversal operations
//
// Student: Liyana Afiqah Binte Jazmi
// Student ID: 35849414
// Project: ICT283 - Assignment 2
// ===============================================================

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>

using std::cout;
using std::endl;

    /**
     * @class Bst
     * @brief A simple recursive Binary Search Tree template
     */

template <class T>
class Bst
{
public:
    /**
     * @brief Default constructor
     */
    Bst();

    /**
     * @brief Destructor
     */
    ~Bst();

    /**
     * @brief Copy constructor. Creates a deep copy of another tree
     * @param other Tree to copy
     */
    Bst(const Bst<T>& other);

    /**
     * @brief Assignment operator. Replaces this tree with a deep copy of another tree.
     * @param other Tree to copy
     * @return Reference to this object
     */
    Bst& operator=(const Bst<T>& other);

    /**
     * @brief Inserts an integer into the BST
     * @param value Value to insert
     */
    void Insert(const T& value);

    /**
     * @brief Search for an integer in the BST
     * @param value Value to search for
     * @return true if found, otherwise return false
     */
    bool Search(const T& value) const;

    /**
     * @brief Print tree contents in in-order traversal
     */
    void InOrder(void (*pf)(const T&)) const;

    /**
     * @brief Print tree contents in pre-order traversal
     */
    void PreOrder(void (*pf)(const T&)) const;

    /**
     * @brief Print tree contents in post-order traversal
     */
    void PostOrder(void (*pf)(const T&)) const;

    /**
     * @brief Delete all nodes from the tree
     */
    void Clear();

    /**
     * @brief Check whether BST invariant holds
     * @return true if valid, otherwise false
     */
    bool IsValid() const;

private:
    /**
     * @struct Node
     * @brief BST node storing one data item and links to children
     */
    struct Node
    {
         T data;          /// Data value stored in this node
         Node *left;      /// Pointer to left child
         Node *right;     /// Pointer to right child

         // Using constructor with member initialisation list to fix -Weffc++ warnings
         Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node *m_root;  /// Pointer to root of the BST

    /**
     * @brief Recursive helper method to insert a value into the BST
     * @param tree Current node in the tree (or subtree)
     * @param value Value to insert
     * @return Pointer to the (possibly modified) subtree
     */
    Node* insert(Node* tree, const T& value);

    /**
     * @brief Recursive helper method to search for a value in the BST
     * @param tree Current node in the tree (or subtree)
     * @param value Value to search for
     * @return true if value found, false otherwise
     */
    bool search(Node* tree, const T& value) const;

    /**
     * @brief Recursive helper method for in-order traversal
     * @param tree Current node in the tree (or subtree)
     */
    void inOrder(Node* tree, void (*pf)(const T&)) const;

    /**
     * @brief Recursive helper method for pre-order traversal
     * @param tree Current node in the tree (or subtree)
     */
    void preOrder(Node* tree, void (*pf)(const T&)) const;

    /**
     * @brief Recursive helper method for post-order traversal
     * @param tree Current node in the tree (or subtree)
     */
    void postOrder(Node* tree, void (*pf)(const T&)) const;

    /**
     * @brief Recursively delete all nodes in a tree
     * @param tree Pointer reference to the root of tree to delete
     */
    void deleteTree(Node*& tree);

    /**
     * @brief Recursively create a deep copy of a tree
     * @param tree Root of tree to copy
     * @return Pointer to the root of the copied tree
     */
    Node* copyTree(const Node* tree);

    /**
     * @brief Recursively validate BST invariant property
     * @param tree Current node in the tree (or subtree)
     * @param min Pointer to minimum allowed value for nodes in this subtree
     * @param max Pointer to maximum allowed value for nodes in this subtree
     * @return true if subtree satisfies BST invariant, false otherwise
     */
    bool checkInvariant(Node* tree, const T* min, const T* max) const;
};

// ===============================================================
// Implementation
// ===============================================================

// Constructor: Initialise empty tree with null root
template <class T>
Bst<T>::Bst()
{
    m_root = nullptr;
}

// Destructor: Clean up all dynamically allocated nodes
template <class T>
Bst<T>::~Bst()
{
    Clear();
}

// Copy Constructor: Create a deep copy of another tree
template <class T>
Bst<T>::Bst(const Bst<T>& other)
{
    m_root = copyTree(other.m_root);
}

// Assignment Operator: Replace contents with a deep copy of another tree
template <class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other)
{
    if(this != &other)
    {
        Clear();  // Delete current tree
        m_root = copyTree(other.m_root);  // Copy other tree
    }

    return *this;
}

// Public Insert: Wrapper that inserts a value into the BST
template <class T>
void Bst<T>::Insert(const T& value)
{
   m_root = insert(m_root, value);
}

// Public Search: Wrapper that searches for a value in the BST
template <class T>
bool Bst<T>::Search(const T& value) const
{
    return search(m_root, value);
}

// Public InOrder: Wrapper for in-order traversal (Left-Root-Right)
template <class T>
void Bst<T>::InOrder(void (*pf)(const T&)) const
{
    inOrder(m_root, pf);
}

// Public PreOrder: Wrapper for pre-order traversal (Root-Left-Right)
template <class T>
void Bst<T>::PreOrder(void (*pf)(const T&)) const
{
    preOrder(m_root, pf);
}

// Public PostOrder: Wrapper for post-order traversal (Left-Right-Root)
template <class T>
void Bst<T>::PostOrder(void (*pf)(const T&)) const
{
    postOrder(m_root, pf);
}

// Public Clear: Delete all nodes from the tree
template <class T>
void Bst<T>::Clear()
{
    deleteTree(m_root);
}

// Public IsValid: Validate that the tree satisfies BST invariant
template <class T>
bool Bst<T>::IsValid() const
{
    return checkInvariant(m_root, nullptr, nullptr);
}

// ===============================================================
// Recursive helper methods implementation
// ===============================================================

// Recursively insert a value into the BST
// If tree is empty, create new node. Otherwise, recursively insert into left or right subtree
template <class T>
typename Bst<T>::Node* Bst<T>::insert(Node* tree, const T& value)
{
    if(tree == nullptr)
    {
        // Using constructor
        return new Node(value);
    }

    if(value < tree->data)
    {
        tree->left = insert(tree->left, value);
    }
    else if(tree->data < value)
    {
        tree->right = insert(tree->right, value);
    }

    return tree;
}

// Recursively search for a value in the BST
// Returns true if found, false if reached null node
template <class T>
bool Bst<T>::search(Node* tree, const T& value) const
{
    if(tree == nullptr)  // Empty tree
    {
        return false;
    }

    if(value == tree->data)  // Found the value
    {
        return true;
    }

    // Recursively search left or right subtree based on BST property
    if(value < tree->data)
    {
        return search(tree->left, value);
    }
    else
    {
        return search(tree->right, value);
    }
}

// In-order traversal: Left-Root-Right
template <class T>
void Bst<T>::inOrder(Node* tree, void (*pf)(const T&)) const
{
    if(tree != nullptr)
    {
        inOrder(tree->left, pf);       // Visit left subtree
        pf(tree->data);            // Execute the pointer function on the data
        inOrder(tree->right, pf);      // Visit right subtree
    }
}

// Pre-order traversal: Root-Left-Right
template <class T>
void Bst<T>::preOrder(Node* tree, void (*pf)(const T&)) const
{
    if(tree != nullptr)
    {
       pf(tree->data);             // Execute the pointer function on the data
        preOrder(tree->left, pf);      // Visit left subtree
        preOrder(tree->right, pf);     // Visit right subtree
    }
}

// Post-order traversal: Left-Right-Root
template <class T>
void Bst<T>::postOrder(Node* tree, void (*pf)(const T&)) const
{
    if(tree != nullptr)
    {
        postOrder(tree->left, pf);      // Visit left subtree
        postOrder(tree->right, pf);     // Visit right subtree
        pf(tree->data);             // Execute the pointer function on the data
    }
}

// Recursively delete all nodes in a tree
template <class T>
void Bst<T>::deleteTree(Node*& tree)
{
    if(tree != nullptr)
    {
        deleteTree(tree->left);   // Delete left subtree
        deleteTree(tree->right);  // Delete right subtree
        delete tree;              // Delete current node
        tree = nullptr;           // Set pointer to null
    }
}

// Recursively create a deep copy of a tree
template <class T>
typename Bst<T>::Node* Bst<T>::copyTree(const Node* tree)
{
    if(tree == nullptr)  // Empty tree
    {
        return nullptr;
    }

    // Create new node with same data
    Node* newNode = new Node;
    newNode->data = tree->data;
    // Recursively copy left and right subtrees
    newNode->left = copyTree(tree->left);
    newNode->right = copyTree(tree->right);

    return newNode;
}

// Recursively validate BST invariant
// min and max pointers track the valid range for the current subtree
template <class T>
bool Bst<T>::checkInvariant(Node* tree, const T* min, const T* max) const
{
    if(tree == nullptr)  // Empty tree is valid
    {
        return true;
    }

    // Check if current node violates the minimum bound
    if(min != 0 && !(*min < tree->data))
    {
        return false;
    }

    // Check if current node violates the maximum bound
    if(max != 0 && !(tree->data < *max))
    {
        return false;
    }
    // Recursively check left and right subtrees with updated bounds
    return checkInvariant(tree->left, min, &(tree->data)) && checkInvariant(tree->right, &(tree->data), max);
}

#endif // BST_H_INCLUDED
