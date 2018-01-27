#include <iostream>
#include "a2_circular_queue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];     //initialize queue for data storage
	size_ = 0;
	capacity_ = 16;     //sets default capacity
	head_ = 0;
	tail_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	items_ = new QueueItem[capacity];       //initialize to specified capacity
	size_ = 0;
	capacity_ = capacity;       //set capacity equal to given capacity
	head_ = 0;
	tail_ = 0;
}

CircularQueue::~CircularQueue()
{
	delete [] items_;       //deallocates memory
}

bool CircularQueue::empty() const       //returns true if queue empty
{    
	return size_==0;
}

bool CircularQueue::full() const        //return true if queue full
{
	return size_ == capacity_;
}

int CircularQueue::size() const     //returns size of the queue
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)        //adds items to back of the queue
{
	if(full())      //checks if full
		return 0;
	
	items_[tail_] = value;      //adds value to the last free element
	tail_ = (tail_ + 1) % capacity_;        //modulo to ensure circular behaviour
	size_++;
	
	return 1;
}

QueueItem CircularQueue::dequeue()      //removes iteams from front of the queue
{
	if(empty())     //checks if queue empty
		return EMPTY_QUEUE;
    
	QueueItem temp = items_[head_];
	head_ = (head_ + 1) % capacity_;        //modulo to ensure circular behaviour
	size_--;
	
	return temp;        //returns the removed value
}

QueueItem CircularQueue::peek() const       //returns value of first element
{
	if(empty())     //checks if queue empty
		return EMPTY_QUEUE;
		
	return items_[head_];   //returns value
}

void CircularQueue::print() const       //prints the queue
{
	std::cout << "[";
	
	if (!empty()){          //ensure queue not empty
		if (tail_ < head_)      //if the head is not the first element
		{
			//print from head to end first
			for (int i = head_; i < size_; i++)
				std::cout << items_[i] << ", ";
            //print from index 0 to tail
			for (int i = 0; i < tail_; i++)
				std::cout << items_[i] << ", ";
			std::cout << items_[tail_];     //print the last element
		}
		else {
            //if the head is the first element, print from head to tail
			for(int i = 0; i < size_-1; i++){
				std::cout << items_[i] << ", ";
			}
			std::cout << items_[size_-1];
		}
	}
	
	std::cout << "]\n";
}

