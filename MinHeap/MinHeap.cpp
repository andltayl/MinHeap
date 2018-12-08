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
	h.insert("1");
	h.insert("5");
	h.insert("4");
	h.insert("3");
	h.insert("2");
	h.print();
	while (h.size() > 0) {
		cout << h.min() << endl;
		h.remove_min();
	}
	h.print();
	return 0;
}