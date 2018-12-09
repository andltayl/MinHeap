// Name: Trey Howell & Anderson Taylor
// Date: 12/7/18
// File: Heap.h
// Description: this is the header file for our min-heap assignment

#include <iostream>
#include <string>
#include <vector>

#ifndef Heap_h
#define Heap_h
class heap {
private:
	std::vector<std::string> buffer;

	void swap(int iOne, int iTwo);

public:
	heap();
	int size();
	void insert(std::string value);
	void remove_min();
	std::string min();
	void print();

	int getLChild(int parentIdx);
	int getRChild(int parentIdx);
	int getParent(int childIdx);

	bool hasLChild(int index);
	bool hasRChild(int index);
	bool hasParent(int index);

	std::string leftChild(int index);
	std::string rightChild(int index);
	std::string parent(int index);

	void fixHeapUp();
	void fixHeapDown();
};

#endif /* Heap_h */

