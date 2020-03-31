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
	heap = NULL;
}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const {
	return !size;
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	return (size == n_capacity);
}

// PURPOSE: Prints the contents of the priority queue; format not specified
void PriorityQueue::print() const {
	for(int i=1; i<=size; i++)
	{
		cout<<"Priority: "<<heap[i]->priorty<<"\t description: "<<heap[i]->describtion<<endl;
	}
}

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")
PriorityQueue::TaskItem PriorityQueue::max() const {
	if(size == 0)
		return TaskItem(-1, "NULL");
	else
		return *heap[1];
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue( TaskItem val ) {
	if (size == n_capacity)
		return false;
	int i = size+1;
	heap[i] = new TaskItem(val);
	while(i>1 && heap[i]->priority > heap[floor(i/2)]->priority)
	{
		TaskItem* temp = heap[i];
		heap[i] = heap[floor(i/2)];
		heap[floor(i/2)] = temp;
	}
	size++;
	return true;
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {
	if(empty())
		return false();
	if(size == 1)
	{
		delete heap[1];
		heap[1] = NULL;
		size--;
		return true;
	}
	int i = 1;
	int child = 1;
	taskItem* storeVal;
	delete heap[i];
	heap[i] = heap[size+1];
	heap[size+1] = NULL;
	
	while( 2*i < n_capacity && (heap[i]->priority < heap[2*i]->priority || heap[i]->priority < heap[2*i + 1]->priority))
	{
		if(heap[2*i]->priority > *heap[2*i+1]->priority)
			child = 2*i;
		else 
			child = 2*i+1;
		
		storeVal = heap[i];
		*heap[i] = *heap[child];
		*heap[child] = *storeVal;
		i = child;
	}	
	size--;
	return true;
}
