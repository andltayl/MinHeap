//
//  main.cpp
//  Min-Heap
//
//  Created by Trey howell and Anderson Taylor on 12/4/18.
// 
//
#include "heap.h"
#include <iostream>
using namespace std;
int main() {
  heap h;           // Basic driver to demontrate the functionality of the min heap.
  h.insert("1");
  h.insert("5");
  h.insert("4");
  h.insert("3");
  h.insert("2");

  cout << "Print the heap in order from left to right, top to bottom:\n";
  
  h.print();

  cout << "\nPrint and remove each element one by one:\n";
  
  while (h.size() > 0) {
    cout << "Curent Size: " << h.size() << "   Current Smallest Element: " << h.min() << endl;
    h.remove_min();
  }
  h.print();
  return 0;
}
