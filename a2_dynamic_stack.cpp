#include <iostream>
#include "a2_dynamic_stack.hpp"

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	//create new array of data
	items_ = new StackItem[16];
	//initialize size and capacity
	size_ = 0;
	capacity_ = 16;
	init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	//create new array of data
	items_ = new StackItem[capacity];
	//initialize size and capacity
	size_ = 0;
	capacity_ = capacity;
	init_capacity_ = capacity;
}

DynamicStack::~DynamicStack()
{
	//recursively delete array
	delete [] items_;
}

bool DynamicStack::empty() const
{
	return size_ == 0;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	//check if stack is full
	if(size_ == capacity_) {
		//copy stack into temporary stack
		StackItem* temp = new StackItem[capacity_];
		for (int i = 0; i < capacity_; i++)
			temp[i] = items_[i];
			
		//resize main stack
		capacity_ = capacity_ * 2;
		items_ = new StackItem[capacity_];
		
		//replace items in main stack
		for (int i = 0; i < capacity_/2; i++)
			items_[i] = temp[i];
	}
	
	//add new value to stack
	items_[size_] = value;
    size_++;
}

StackItem DynamicStack::pop()
{
	//cannot pop from an empty stack
	if (empty())
		return EMPTY_STACK;

	size_--;
	
	//check if stack's size should be reduced
	if (size_  <= capacity_ / 4){
		//reduce size and ensure stack remains above initial capacity
		capacity_ = capacity_ / 2;
		if (capacity_ >= init_capacity_){
			//copy items to a temporary stack
			StackItem* temp = new StackItem[capacity_];
			for (int i = 0; i < capacity_; i++)
				temp[i] = items_[i];
				
			//resize stack and return items to their positions
			items_ = new StackItem[capacity_];
			for (int i = 0; i < capacity_; i++)
				items_[i] = temp[i];
		} else {
			//return capacity to normal if smaller than initial capacity
			capacity_ *= 2;
		}
	}
	
	//return last item
	return items_[size_]; 
}

StackItem DynamicStack::peek() const
{
	//nothing to see in an empty stack
	if (empty())
		return EMPTY_STACK;
	
	//return last item without removing
	return items_[size_ - 1];
}

void DynamicStack::print() const
{
	std::cout << "[";
	//iterate through stack, output values in order (like an array)
	if (!empty()){
		for(int i = 0; i < size_-1; i++){
			std::cout << items_[i] << ", ";
		}
		//account for no comma on last item
		std::cout << items_[size_-1];
	}
	std::cout << "]\n";
}

