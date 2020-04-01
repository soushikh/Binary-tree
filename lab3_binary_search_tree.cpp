#include <iostream>
#include "lab3_binary_search_tree.hpp"

using namespace std;

// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree() {
	root = NULL;
	size = 0;
}

//Purpose: Delete node in tree
void delNodes(TaskItem* node) {
if (node == NULL)
	return;
else
{
	delNodes(node->right);
	delNodes(node->left);
}
delete node;
node = NULL;
}


int maxVal(TaskItem* node) {
	
int max = node->priority;	
	
if (node == NULL)
	return;
else
{
	if(node->priority > max)
	max = node->priority;
		
	maxVal(node->right);
	maxVal(node->left);
}
return max;
}


int minVal(TaskItem* node) {
	
int min = node->priority;	
	
if (node == NULL)
	return;
else
{
	if(node->priority < min)
	min = node->priority;
		
	minVal(node->right);
	minVal(node->left);
}
delete node;
node = NULL;
}













// PURPOSE: Explicit destructor of the class BinarySearchTree   //Cole
BinarySearchTree::~BinarySearchTree() {
delNodes(root);
}

// PURPOSE: Returns the number of nodes in the tree        //Cole
unsigned int BinarySearchTree::get_size() const {
	return size;
}

// PURPOSE: Returns the maximum value of a node in the tree    //Cole
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::max() const {
	return BinarySearchTree::TaskItem(-1, "N/A");
}

// PURPOSE: Returns the minimum value of a node in the tree    //Cole
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const {
	return BinarySearchTree::TaskItem(-1, "N/A");
}

// PURPOSE: Returns the tree height					//Cole
unsigned int BinarySearchTree::height() const {
	return 0;
}

// PURPOSE: Prints the contents of the tree; format not specified      //Cole
void BinarySearchTree::print() const {
}

// PURPOSE: Returns true if a node with the value val exists in the tree	//Soushi
// otherwise, returns false
bool BinarySearchTree::exists( BinarySearchTree::TaskItem val ) const {
	return false;
}

// PURPOSE: Optional helper function that returns a pointer to the root node     //Soushi
BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {
    return NULL;
}

// PURPOSE: Optional helper function that returns the root node pointer address       //Soushi  
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    return NULL;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node     //Soushi
int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	return 0;
}

// PURPOSE: Inserts the value val into the tree if it is unique                 //Soushi
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert( BinarySearchTree::TaskItem val ) {
    return false;
}

// PURPOSE: Removes the node with the value val from the tree		//Cole
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove( BinarySearchTree::TaskItem val ) {
    return false;
}
