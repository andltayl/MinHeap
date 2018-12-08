//
//  main.cpp
//  Min-Heap
//
//  Created by Trey howell on 12/4/18.
//  Copyright © 2018 Trey howell. All rights reserved.
//
#include "Heap.h"
#include <iostream>
using namespace std;
int main() {
	heap h;
	h.insert("Trey");
	h.insert("Anderson");
	h.insert("assignment 9");
	h.insert("this is a small test");
	h.insert("this is a test for heap");
	h.print();
	while (h.size() > 0) {
		cout << h.min() << endl;
		h.remove_min();
	}
	h.print();
	return 0;
}