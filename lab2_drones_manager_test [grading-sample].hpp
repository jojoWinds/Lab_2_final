#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;
#include <iostream>
using namespace std;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
    bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
    }

	// PURPOSE: insert_front() and insert_back() on zero-element list
    bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))		
	    return true;
    }

	// PURPOSE: select() and search() work properly
    bool test3() {
		DronesManager manager1;
		
		const int num_elems = 5;
		for (unsigned int i = 0; i < num_elems; i++) {
			(manager1.insert_back(DronesManager::DroneRecord(i*100)))? cout << i << " true" << endl: cout << i << " false" << endl;
		}

		unsigned int idx = 3;
		(manager1.search(manager1.select(idx)) == idx)? cout << "true" << endl: cout << "false" << endl;
		(manager1.select(num_elems + 1) == DronesManager::DroneRecord(400))? cout << "true" << endl: cout << "false" << endl;
		(manager1.search(1000) == manager1.get_size())? cout << "true" << endl: cout << "false" << endl;
		
		
		for (unsigned int i = 0; i < num_elems; i++) {
			(manager1.select(i) == DronesManager::DroneRecord(i*100))? cout << i << " true" << endl: cout << i << " false" << endl;
		}
		(manager1.first->prev == NULL && manager1.last->next == NULL)? cout << "true" << endl: cout << "false" << endl;
		
		manager1.print();
		
		cout << endl << endl;
	    return true;
    }
    
    // PURPOSE: remove_front() and remove_back() on one-element list
    bool test4() {
		DronesManager manager1, manager2;
		(manager1.insert_front(DronesManager::DroneRecord(100)))? cout << "true" << endl: cout << "false" << endl;
		(manager2.insert_front(DronesManager::DroneRecord(100)))? cout << "true" << endl: cout << "false" << endl;
		(manager1.remove_front())? cout << "true" << endl: cout << "false" << endl;
		(manager2.remove_back())? cout << "true" << endl: cout << "false" << endl;
		
		(manager1.first == NULL && manager1.last == NULL)? cout << "true" << endl: cout << "false" << endl;
		(manager2.first == NULL && manager2.last == NULL)? cout << "true" << endl: cout << "false" << endl;
		(manager1.get_size() == manager2.get_size() && manager1.get_size() == 0)? cout << "true" << endl: cout << "false" << endl;
		(manager1.empty() == true && manager2.empty() == true)? cout << "true" << endl: cout << "false" << endl;
				
	    return true;
    }
    
    // PURPOSE: replace() and reverse_list() work properly
    bool test5() {
    	DronesManager manager;
		const int num_elems = 8;
		for (unsigned int i = 0; i < num_elems; i++) {
			(manager.insert_back(DronesManager::DroneRecord(i)))? cout << "true" << endl: cout << "false" << endl;
		}
		
		manager.print();
		cout << endl << endl;
		
		(manager.replace(0, DronesManager::DroneRecord(8)))? cout << "true" << endl: cout << "false" << endl;
		(manager.replace(3, DronesManager::DroneRecord(9)))? cout << "true" << endl: cout << "false" << endl;
		(manager.replace(7, DronesManager::DroneRecord(10)))? cout << "true" << endl: cout << "false" << endl;
	
		(*manager.first == DronesManager::DroneRecord(8))? cout << "true" << endl: cout << "false" << endl;
		(*manager.last == DronesManager::DroneRecord(10))? cout << "true" << endl: cout << "false" << endl;
		
		manager.print();
		cout << endl << endl;
		
		(*(manager.first->next->next->next) == DronesManager::DroneRecord(9))? cout << "true" << endl: cout << "false" << endl;
	
		int test_values[8] = {10, 6, 5, 4, 9, 2, 1, 8};
		(manager.reverse_list())? cout << "true" << endl: cout << "false" << endl;
		for (unsigned int i = 0; i < num_elems; i++) {
			(manager.select(i) == DronesManager::DroneRecord(test_values[i]))? cout << "true" << endl: cout << "false" << endl;
		}
	
		(manager.first->prev == NULL && manager.last->next == NULL)? cout << "true" << endl: cout << "false" << endl;
		
	    return true;
    }
    
    // PURPOSE: insert_front() keeps moving elements forward
    bool test6() {
    	DronesManager manager;
		const int num_elems = 5;
		for (unsigned int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(i)))
			ASSERT_TRUE(manager.get_size() == (i + 1))
			ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(i))
	        
			DronesManager::DroneRecord* n = manager.first;
			for (unsigned int j = 0; j <= i; j++) {
				DronesManager::DroneRecord expected_value = DronesManager::DroneRecord(i - j);
				ASSERT_TRUE(n != NULL && *n == expected_value)
				n = n->next;
			}
		}	
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
	    return true;
    }
    
    // PURPOSE: inserting at different positions in the list
    bool test7() {
    	DronesManager manager;
		for (unsigned int i = 0; i < 4; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(4), 1))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(5), 1))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(6), 5))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(7), 7))
	
		// Check that the list has the right values
		int expected_values[] = {0, 5, 4, 1, 2, 6, 3, 7};
		ASSERT_TRUE(manager.get_size() == 8)
		DronesManager::DroneRecord* n = manager.first;
		for (unsigned int i = 0; i < manager.get_size(); i++) {
			ASSERT_TRUE(n != NULL && *n == DronesManager::DroneRecord(expected_values[i]))
			n = n->next;
		}
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
 	    return true;
    }
    
    // PURPOSE: try to remove too many elements, then add a few elements
    bool test8() {
    	DronesManager manager;
		for (unsigned int i = 0; i < 4; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}
    	
    	for (unsigned int i = 0; i < 4; i++) {
			ASSERT_TRUE(manager.remove_back())
		}
    	
		// Try a bunch of invalid commands.
		ASSERT_FALSE(manager.remove_front())
		ASSERT_FALSE(manager.remove_front())
		ASSERT_FALSE(manager.remove(0))
		ASSERT_TRUE(manager.empty() && manager.get_size() == 0)
	
		int expected_value = 1234;
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(expected_value), 0))
		ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(expected_value) &&
	                *manager.last == DronesManager::DroneRecord(expected_value))
	                
	    ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
	    ASSERT_TRUE(manager.first == manager.last)
	    return true;
    }
    
 	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		DronesManager manager;
		ASSERT_FALSE(manager.remove(0))
		ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(32)))
		ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(44)))
		ASSERT_FALSE(manager.insert(DronesManager::DroneRecord(12),3))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(12),2))
		ASSERT_TRUE(manager.remove_back())
		ASSERT_FALSE(manager.remove(5))
		ASSERT_TRUE(manager.remove_front())
		ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(88)))
		ASSERT_FALSE(manager.insert(DronesManager::DroneRecord(12345),6))
		ASSERT_TRUE(manager.remove(1))
		ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(99),0))
		
		// Check that the manager has the right values
		ASSERT_TRUE(manager.select(0) == DronesManager::DroneRecord(99) && *manager.first == DronesManager::DroneRecord(99))
		ASSERT_TRUE(manager.select(1) == DronesManager::DroneRecord(32) && *manager.last == DronesManager::DroneRecord(32))

		ASSERT_TRUE(manager.first->next == manager.last && manager.last->prev == manager.first)
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)

		return true;
	}    
	    	
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
    	DronesManager manager;
	   	ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(25)))
	   	ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(45)))   
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(11),2))
	   	ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(15)))
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(72),3))
	   	ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(52)))   
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(75),2))
	   	ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(82)))
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(43),3))
	   	ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(21),1))

		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)
	
		int test_values[10] = {52, 21, 15, 75, 43, 45, 25, 72, 11, 82};
		ASSERT_TRUE(manager.reverse_list());
		for (unsigned int i = 0; i < 10; i++) {
			ASSERT_TRUE(manager.select(i) == DronesManager::DroneRecord(test_values[9-i]))
		}

    	for (unsigned int i = 0; i < 10; i++) {
			ASSERT_TRUE(manager.remove_back())
		}

		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)	
		
	   	return true;
	}  
};


#endif
