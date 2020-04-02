#include <iostream>
#include "lab3_binary_search_tree.hpp"

using namespace std;

// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree() {
	root = NULL;
	size = 0;
}

//Purpose: Delete node in tree (added helper function)
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
	
if (size == 0)
	return BinarySearchTree::TaskItem(-1, "N/A");
	
TaskItem* node = root;
	while(node->right!= NULL)
	{
		node = node->right;
	}
		return *node;
}
}
	
	
// PURPOSE: Returns the minimum value of a node in the tree    //Cole
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const {

if (size == 0)
	return BinarySearchTree::TaskItem(-1, "N/A");
	
TaskItem* node = root;
	while(node->left!=NULL)
	{
		node = node->left;
	}
	return *node;
}
}

//PURPOSE: Determines the tree height

unsigned int findHeight(TaskItem *node)
{
	if(node == NULL)
		return 0;
	else
	{
		return 1 + max(findHeight(node->left), findHeight(node->right));
	}
}

// PURPOSE: Returns the tree height					//Cole
unsigned int BinarySearchTree::height() const {
	if (size == 0 || size == 1)
	return 1;
	
	else
	findHeight(root);
}

void printContents(TaskItem* node)
{
	
	if(node == NULL)
	cout << "";
	else
	{
		cout << node->priority << endl; 
		printContents(node->left);
		printContents(node->right);
	}
}


// PURPOSE: Prints the contents of the tree; format not specified      //Cole
void BinarySearchTree::print() const {
	printContents(root);
}

// PURPOSE: Returns true if a node with the value val exists in the tree	//Soushi
// otherwise, returns false
bool BinarySearchTree::exists( BinarySearchTree::TaskItem val ) const {
	TaskItem* cur = heap;
	while(cur)
	{
		if(cur->priority == val.priority)
			return true;
		else if(val.priority < cur->priority)
			cur = cur->left;
		else 
			cur = cur->right;
	}
	return false;
}

// PURPOSE: Optional helper function that returns a pointer to the root node     //Soushi
BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {
    return root;
}

// PURPOSE: Optional helper function that returns the root node pointer address       //Soushi  
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    	if(size == 0)
		return NULL;
	else
		return &root;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node     //Soushi
int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	return 0;
}

// PURPOSE: Inserts the value val into the tree if it is unique                 //Soushi
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert( BinarySearchTree::TaskItem val ) {
    	TaskItem** cur = &root;
	while(*cur)
	{
		if(**cur->priority == val.priority)
			return false;
		else if(val.priority < **cur->priority)
			cur = (*cur)->left;
		else 
			cur = (*cur)->right;
	}
	*cur = new TaskItem(val);
	return true;
}















// PURPOSE: Removes the node with the value val from the tree		//Cole
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove( BinarySearchTree::TaskItem val, TaskItem* node) {
	
TaskItem* temp;
 
if(node->left->priority == val||node->right->priority == val)
{
	//Case 1: Node to be deleted is a leaf node
	if(node->left->left == NULL && node->left->right == NULL)
	{
		delete node->left;
		node->left = NULL;
	}
	else if(node->right->left == NULL && node->right->right == NULL)
	{
		delete node->right;
		node->right = NULL;
	}
	
	//Case 2: Node to be deleted has one child
	else if(node->left->left == NULL && node->left->right != NULL)
	{
		temp = node->left->right;
		delete node->left;
		node->left = temp;
	}
	else if (node->left->left != NULL && node->left->right == NULL)
	{
		temp = node->left->left;
		delete node->left;
		node->left = temp;
	}
	else if (node->right->left == NULL && node->right->right != NULL)
	{
		temp = node->right->right;
		delete node->right;
		node->right = temp;
	}
	else if (node->right->left != NULL && node->right->right == NULL)
	{
		temp = node->right->left;
		delete node->right;
		node->right = temp;
	}
	
	//Case 3: Node to be deleted has two children
}

	
	
	
	
if(node == NULL)
return;
else
{
	remove(val, node->left);
	remove(val, node->right);
}

	

	
}
