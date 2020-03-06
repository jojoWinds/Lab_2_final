/*
	Assignment: Lab 2
	Authors: Friendly Hippo and Long Giraffe (AKA Rania and Odianosen)
	Student numbers: Odianosen (20827576), Rania (20712723)
	Submission deadline: Feb. 14, 2020
	File name: lab2_drones_manager_test.hpp
*/

#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;


class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0);
		ASSERT_TRUE(manager.empty() == true);
		ASSERT_TRUE(manager.first == NULL);
		ASSERT_TRUE(manager.last == NULL);
	    return true;
	}
	
//	 PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1);
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last);
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last);
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL);
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL);
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100));
	    return true;
	}
	
//	 TODO: Implement all of the test cases below
//	
//	 PURPOSE: select() and search() work properly
	bool test3() {
		cout << "Test cases for [test3]----------------------------------" << endl;
		cout << "Test cases for 'select()' function------" << endl;
		
		//case 1: search in an empty list
		DronesManager manager_1;
		ASSERT_FALSE(manager_1.search(2));
		
		//case 2: pass node that doesn't exist in list (index exceeds size)
		DronesManager manager_2;
		manager_2.insert_front(DronesManager::DroneRecord(100));
		manager_2.insert_front(DronesManager::DroneRecord(101));
		manager_2.insert_front(DronesManager::DroneRecord(102));
		ASSERT_TRUE(!manager_2.search(3));
		
		//case 3: pass a valid node index. more than one node in the list
		ASSERT_TRUE(manager_2.search(2));
				
		cout << "Test cases for 'search()' function------" << endl;
		
		
	    return true;
	}
	
	//need to do (remove_back)*****************************************************
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
		cout << "Test cases for [test4]----------------------------------" << endl;
		cout << "Test cases for 'remove_front()' function------" << endl;
		
		//case 1: removing node when list is empty
		DronesManager manager_1;
		ASSERT_TRUE(!manager_1.remove_front());
		
		//case 2: removing node when list has at least one node
		DronesManager manager_2;
		manager_2.insert_front(DronesManager::DroneRecord(100));
		ASSERT_TRUE(manager_2.remove_front());
		
		//case 3: removing node that is null
		DronesManager manager_3;
		manager_3.insert_front(DronesManager::DroneRecord());
		ASSERT_TRUE(!manager_3.remove_front());
		
		
		cout << "Test cases for 'remove_back()' function------" << endl;
		
		//case 1: removing node when list is empty
		DronesManager manager_4;
		ASSERT_TRUE(!manager_4.remove_back());
		
		//case 2: removing node when list has at least one node
		DronesManager manager_5;
		manager_5.insert_front(DronesManager::DroneRecord(100));
		ASSERT_TRUE(manager_5.remove_back());
		
		//case 3: removing node that is null
		DronesManager manager_6;
		manager_6.insert_front(DronesManager::DroneRecord());
		ASSERT_TRUE(!manager_6.remove_back());
		
		
	    return true;
	}
	
	//need to do (reverse_list)*****************************************************
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
	cout << "Test cases for [test5]----------------------------------" << endl;
	cout << "Test cases for 'replace()' function------" << endl;
	DronesManager manager_5;
	manager_5.insert_front(DronesManager::DroneRecord(102));
	manager_5.insert_front(DronesManager::DroneRecord(101));
	manager_5.insert_front(DronesManager::DroneRecord(100));
	
	//manager structure - 100, 101, 102
	
	ASSERT_TRUE(manager_5.replace(0, DronesManager::DroneRecord(1)) == true);
//	manager_5.print();
//	cout << endl;
	//expected : 1, 101, 102
	
	ASSERT_TRUE(manager_5.replace(2, DronesManager::DroneRecord(3)) == true);
//	manager_5.print();
//	cout << endl;
//	//expected : 1, 101, 3
//	
	ASSERT_FALSE(manager_5.replace(5, DronesManager::DroneRecord(102)) == true);
//	//expected: true because 5 is bigger than size so false false = true
		
cout << "Test cases for 'reverse_list()' function------" << endl;

	ASSERT_TRUE(manager_5.reverse_list() == true);
//	manager_5.print();
//	//expected: 3, 101, 1

	DronesManager manager_5_0;
	ASSERT_FALSE(manager_5_0.reverse_list() == true);
//	//expected: Empty list so returns false and false false = true

	DronesManager manager_5_1;
	for (int val = 1; val <= 6; val++)
	{
		manager_5_1.insert_front(DronesManager::DroneRecord(val));	
	}
	
	ASSERT_TRUE(manager_5_1.reverse_list());
//	manager_5_1.print();
//	//expected: 1, 2, 3, 4, 5, 6		
		
	    return true;
	}
	
	//need to do*****************************************************
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
		cout << "Test cases for [test6]----------------------------------" << endl;
		cout << "Test cases for 'insert_front()' function------" << endl;
		DronesManager manager_6;
		
		for(int val = 1; val <=10; val++)
		{
			ASSERT_TRUE(manager_6.insert_front(DronesManager::DroneRecord(val)) && true);
		}
	    return true;
	}
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
		cout << "Test cases for [test7]----------------------------------" << endl;
		cout << "Test cases for inserting at different positions in the list------" << endl;
			
		DronesManager manager_7;
		
		for (int val = 1; val <=5; val++)
		{
			ASSERT_TRUE(manager_7.insert(DronesManager::DroneRecord(val), val-1) && true);
		}
			
		ASSERT_TRUE(manager_7.insert(DronesManager::DroneRecord(1),-1) && false);
		ASSERT_TRUE(manager_7.insert(DronesManager::DroneRecord(2),6) && false);
		ASSERT_TRUE(manager_7.insert(DronesManager::DroneRecord(56), 567) && false);
				
	    return true;
	}
	
	//need to do (as a team)*****************************************************
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
		cout << "Test cases for [test8]----------------------------------" << endl;
		cout << "Test cases for remove too many elements, then add a few elements------" << endl;
		
		//setup inserting elements into list
		DronesManager manager_1;
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(100)) == true);
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(102)) == true);
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(103)) == true);
		
		//removing more than size of list
		ASSERT_TRUE(manager_1.remove_back() == true);
		ASSERT_TRUE(manager_1.remove_back() == true);
		ASSERT_TRUE(manager_1.remove_back() == true);
		ASSERT_TRUE(manager_1.remove_back() == false);
		
		//inserting few elements
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(100)) == true);
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(102)) == true);
					
	    return true;
	}
	
	//need to do (as a team)*****************************************************
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9()
	{
		cout << "Test cases for [test9]----------------------------------" << endl;
		cout << "Test cases for lots of inserts and deletes, some of them invalid------" << endl;
		
		DronesManager manager_9;

		//insert front. Expected is true
		for (int val = 1; val <=6; val++)
		{
			ASSERT_TRUE(manager_9.insert_front(DronesManager::DroneRecord(val)) && true);
		}
		
		//insert back. Expected is true
		for (int val = 1; val <=3; val++)
		{
			ASSERT_TRUE(manager_9.insert_back(DronesManager::DroneRecord(val+5)) && true);
		}
		
		//insert. Invalid operation in terms of index so false == false should evaluate to true
		for (int val = 1; val <=3; val++)
		{
			ASSERT_TRUE(manager_9.insert(DronesManager::DroneRecord(val+100), val^50 ) && false);
		}
		
		//remove back. Since size is 9, valid so expected is true
		for (int val = 1; val <=3; val++)
		{
			ASSERT_TRUE(manager_9.remove_back() && true);
		}
		
		//remove front. Size is now 6, valid so expected is true
		for (int val = 1; val <=3; val++)
		{
			ASSERT_TRUE(manager_9.remove_front() && true);
		}
		
		//remove. Size of 3 so should be valid. Expected to remove everything and still evaluate to true
		for (int val = 1; val <=3; val++)
		{
			ASSERT_TRUE(manager_9.remove(val) && true);
		}
		
		//remove. Size of 0 so should return false. false == false is true so Expected is true
		for (int val = 1; val <=3; val++)
		{
			ASSERT_TRUE(manager_9.remove(val) && false);
		}
		
		//add string characters.
		
		return true;
	}    
	
	//need to do (as a team)*****************************************************
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
		
		cout << "Test cases for [test10]----------------------------------" << endl;
		cout << "Test cases for lots of inserts, reverse the list, and then lots of removes until empty------" << endl;
		
		//lots of inserts
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(100)) && true);
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(102)) && true);
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(103)) && true);
		ASSERT_TRUE(manager_1.insert_front(DronesManager::DroneRecord(104)) && true);
		
		//reverse the list
		ASSERT_TRUE(manager_1.reverse() && true);
		
		//lots of removes until empty
		ASSERT_TRUE(manager_1.remove_back() && true);
		ASSERT_TRUE(manager_1.remove_back() && true);
		ASSERT_TRUE(manager_1.remove_back() && true);
		ASSERT_TRUE(manager_1.remove_back() && true);
		ASSERT_TRUE(manager_1.remove_back() && true);
		
	   return true;
	} 
};
#endif
