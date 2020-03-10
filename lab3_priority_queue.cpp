#include "lab3_priority_queue.hpp"

using namespace std;

// PURPOSE: Parametric constructor 
// initializes heap to an array of (n_capacity + 1) elements
PriorityQueue::PriorityQueue(unsigned int n_capacity) {
	heap = new TaskItem*[n_capacity+1];
}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {
	for(int i = 1; i < n_capacity + 1; i++)
	{
		delete heap[i];
	}
	delete heap;
}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const {
	return !(size);
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	return (size == n_capacity);
}

// PURPOSE: Prints the contents of the priority queue; format not specified
void PriorityQueue::print() const {
	for(int i = 1; i < n_capacity + 1; i++)
	{
		cout<<heap[i]->priority<<" "<<heap[i]->description<<endl;
	}
}

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")
PriorityQueue::TaskItem PriorityQueue::max() const {
	return TaskItem(-1, "NULL");
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue( TaskItem val ) {
	TaskItem* node = new TaskItem(val);
	int index = size+1;
	int root = floor(index/2);
	heap[index] = node;
	while(heap[root]->priority < node->priority)
	{
		TaskItem* temp = heap[root];
		heap[root] = heap[index];
		heap[index] = temp;
		index = root;
		root = floor(index/2);
	}
	return false;
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {
	return false;
}
