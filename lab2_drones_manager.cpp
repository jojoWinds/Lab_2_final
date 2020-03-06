/*
	Assignment: Lab 2
	Authors: Friendly Hippo and Long Giraffe (AKA Rania and Odianosen)
	Student numbers: Odianosen (20827576), Rania (20712723)
	Submission deadline: Feb. 14, 2020
	File name: lab2_drones_manager.cpp
*/

#include "lab2_drones_manager.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
	// creates a new empty DronesManager
	//DronesManager() : prev(NULL), next(NULL), size(0), DroneRecord(){};
	first = NULL;
	last = NULL;
	size = 0;
	DroneRecord();
}

//complete
DronesManager::~DronesManager() {
	
	DroneRecord* cur = first;
	while(cur)
	{
		cur = cur->next;
		delete first;
		first = cur;
	}
	
	first = last = NULL;
	size = 0;
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	bool status = true;
	
	//compares elements of objects passed into parameter to each other
	if( (lhs.droneID == rhs.droneID) && (lhs.range == rhs.range) && (lhs.yearBought == rhs.yearBought) ) {}
	else {status = false;}
	
	return status;
}

//complete
unsigned int DronesManager::get_size() const {
	//run through DLL and count number of nodes (DroneRecord)
	int DLL_size = 0;

	//case 1: list contains no node
	if (first == NULL)
	{
		DLL_size = 0;
	}
	//case 2: list contains 1 node
	else if (first == last)
	{
		DLL_size = 1;
	}
	//case 3: list contains more than 1 node
	else
	{
		DroneRecord* current_node = first;			  
		while (current_node->next != NULL) //traverse throught list
		{
			current_node = current_node->next;
			DLL_size++;
		}
		DLL_size++;
	}
	
	return DLL_size;
}

bool DronesManager::empty() const {
	bool status = true;
	
	//first case: list is already empty
	if(first == NULL){}
	else{status = false;}
	
	return status; //***********************************************************chaged from 'false' to 'status'
}

//complete (need to update 'complete vers' in drive)
DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	//value to be returned is the node itself (DroneRecord)
	//index goes from: 0 to size-1
	DroneRecord* current_node = first;

	//case 1: empty list
	if (first == NULL)
	{
		return DroneRecord();
	}
	//case 2: when index exceeds size of list
	else if (index > this->get_size()-1)
	{
		while(current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		return *current_node;
		
		//return last; //if index is invalid, returns last element
	}
	//case 3: one node
	else if ((first == last) && (last != NULL))
	{
		if (index == 0)
			return DroneRecord(*current_node); //*current_node;
		else
			return DroneRecord();
	}
	//case 4: more than one node
	else
	{
		int position = 0;
		while (current_node->next != NULL) //traverse throught list
		{
			if (position == index)
				return *current_node;
			current_node = current_node->next;
			position++;
		}
	}
	
	return DroneRecord();
}

unsigned int DronesManager::search(DroneRecord value) const {
		
	//first case: list is empty
	if(!first)
	{
		return 0;
	}
	else
	{
		DroneRecord* current_node = first;
		int cur_index = 0;
		while(current_node)
		{
			if (*current_node == value)
				return cur_index;
			current_node = current_node->next;
			cur_index++;
		}
		return cur_index+1; //value not found
	}	
}

//complete
void DronesManager::print() const {
	/*printing structure:
		Node index: 
		Drone ID:
		Range: 
		Year bought: 
		Drone type: 
		Manufacturer: 
		Description: 
		Battery type:
	*/

	DroneRecord* current_node = first;
	int position = 0;

	//case 1: list is empty
	if (first == NULL)
	{
		cout << "This list is empty" << endl << endl;
	}
	//case 2: one node in list
	else if (first == last)
	{
		cout << "Node index: " << position << endl;
		cout << "Drone ID: " << current_node->droneID << endl;
	}
	//case 3: list contains more than one node
	else
	{
		for(int k = 0; k < size; k++)
		{
			cout << "Node index: " << position << endl;
			cout << "Drone ID: " << current_node->droneID << endl;

			current_node = current_node->next;
			position++;
		}
	}
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	
	//invalid operation if index is bigger than the size
	//DroneRecord obj_val = value;
	DroneRecord *current_node = first;
	DroneRecord *before = NULL;
	DroneRecord *after = NULL;
	

	// if index is greater than size, invalid operation
	if(index >= this->get_size())
	{
		return false;
	}
	else
	{
		//1st case: empty list
		if(current_node == NULL || index == 0)
		{
			insert_front(value);
//			cout << "insert at front" << endl;
			return true;
		}

		//2nd case: index is equal to the number of indices list has
		else if(index == (*this).get_size())
		{
			insert_back(value);
//			cout << "insert at back" << endl;
			return true;
		}

		//3rd case: index is in the middle of the list
		else
		{
//			cout << "insert at index" << endl;
			for(int position = 0; position < index; position++)
			{
				current_node = current_node->next;
				before = current_node->prev;
				after = current_node->next;

//				cout << "inside loop?" <<" " <<position << endl << endl;
			}
			
//			before = current_node->prev;
//			after = current_node->next;
			
			DroneRecord* temp = new DroneRecord(value);			
			before->next = temp;
			temp->prev = before;			
			temp->next = current_node;
			current_node->prev = temp;
			
			size++;

			return true;
		}
	}
	
	return false;
}

//complete
bool DronesManager::insert_front(DroneRecord value) {
	//insert node at front of the list
	DroneRecord* current_node = first;

	//case 1: list is empty
	if (first == NULL)
	{
		first = new DroneRecord(value);
		last = first;
		size++;
		return true;
	}
	//case 2: list contains one or more node(s)
	else
	{
		DroneRecord* temp = new DroneRecord(value);
		
		current_node->prev = temp; //current node points to new node
		temp->next = current_node; //new node points to current node
		first = temp; //first points to new node
		temp->prev = NULL; //new node points to NULL
		size++; //size increase
		return true;
	}
	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
	
	//case 1: list is empty
	if (first == NULL)
	{
		DroneRecord* temp = new DroneRecord(value);
		first = temp;
		last = temp;
		size++;
		return true;
	}

	//case 2: list contains one or more node
	else
	{
		DroneRecord* current_node = first;
		while(current_node->next)
		{
			current_node = current_node->next;
		}
		DroneRecord* temp = new DroneRecord(value);
		
		current_node->next = temp; //insert at end. set next and prev = NUL in the constructor
		temp->next = NULL;
		temp->prev = current_node;
		last = temp;
		size++;
		
		return true;
	}
		
	return false;
}

//complete
bool DronesManager::remove(unsigned int index) {
	//remove node at index position.
	
	//Checking conditions:
	//is index > size ? return false
	if (index > size-1)
		return false;
	
	//List of cases:
	//case 1: empty list
	else if (first == NULL)
	{
		return false;
	}
	//case 2: node is first in list
	else if (index == 0)
	{
		remove_front();
		return true;
	}
	//case 3: node at end of list
	else if (index == size-1)
	{
		remove_back();
		
		return true;
	}
	//case 4: node in btw 2 nodes
	else
	{
		DroneRecord *current_node = first;
		DroneRecord *before = NULL;
		DroneRecord *after = NULL;
		
		for(int position = 0; position < index; position++)
		{
			current_node = current_node->next;
			before = current_node->prev;
			after = current_node->next;
		}
		
		before->next = after;
		after->prev = before;
		delete current_node;
		current_node = NULL;		
		
		size++;
		return true;
	}
	//case 5: node doesn't exist (out of range. exceeds size of list)	
	return false;
}

bool DronesManager::remove_front()
 {
 	DroneRecord* curr = first;
 	//1st case: empty list
 	if(first == NULL)
 	{return false;}
 	
 	else if(curr->next == NULL)
	 {		
		delete curr;
		curr = NULL;
		
		size--;	
		return true; 		
	 }
	 else
	 {
		first = curr->next;
		curr->next->prev = NULL;
		delete curr;
		curr = NULL;
			
		size--;
		return true;
	 }
 	//2nd case: list with one node or multiple

}

//complete
bool DronesManager::remove_back() {
	
	DroneRecord* cur_node = last;
	DroneRecord* prev_node = last->prev;
	
	//case 1: if empty list
	if (!first)
	{
		return false;
	}
	//case 2: only one node in list
	else if (first->next == NULL)
	{
		DroneRecord* curr = first;
		delete curr;
		curr = NULL;		
		size--;	
		return true; 
	}
	//case 3: if more than one node in list
	else
	{
		DroneRecord* current_node = first;
		while(current_node->next->next) //iterate until second last node
		{
			current_node = current_node->next;
		}
		delete current_node->next;
		current_node->next = NULL;
		last = current_node;
		--size;
		return true;
	}
	
	return false;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	
	int position = 0;
	
	//1st case: empty list
	if( index > this->get_size() )
	{
//		cout << "Function didn't work and exited" << endl;
		return false;
	}	
	else
	{
		DroneRecord *current_node = first;
		DroneRecord *before = NULL;
		DroneRecord *after = NULL;
		
		for(int position = 0; position < index; position++)
		{
			current_node = current_node->next;
			before = current_node->prev;
			after = current_node->next;
		}
		
		DroneRecord* temp = new DroneRecord(value);
		before->next = temp;
		after->prev = temp;
		temp->prev = before;
		temp->next = after;
		
		delete current_node;	
		current_node = NULL;		
				
//		cout << "Function is working and we are here" << endl;
		return true;
	}
	
	//case 4: node in btw 2 nodes

	
	return false;
}

//complete
bool DronesManager::reverse_list() {
	
	//case 1: if emtpy list
	if (first == NULL)
	{
		return false;
	}
	//case 2: if only one node in list
	else if (first == last)
	{
		return true;
	}	
	//case 3: if more than one node in list
	else
	{
		DroneRecord* temp = NULL;
		DroneRecord* current = first;
		
		DroneRecord* temptemp = first;
		first = last;
		last = temptemp;
		
		while(current!=NULL)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		
		return true;
	}
	
	return true;
}
