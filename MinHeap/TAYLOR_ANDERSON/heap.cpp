#include "heap.h"

using namespace std;


void heap::swap(int iOne, int iTwo)  //Helper function to swap two nodes in the tree.
{
  string temp = buffer[iOne];
  buffer[iOne] = buffer[iTwo];
  buffer[iTwo] = temp;
}

heap::heap()
{
}

int heap::size()  //Simply returns the size of the min heap.
{
  return buffer.size();
}

void heap::insert(std::string value)  // Inserts a new node into the next spot in the tree.
{
  buffer.push_back(value);
  fixHeapUp();
}

void heap::remove_min()  // Removes the first element in the heap.
{
  buffer[0] = buffer[buffer.size() - 1];
  buffer.pop_back();
  fixHeapDown();
}

string heap::min()  // Returns the value of the smallest element in the heap.
{
  return buffer[0];
}

void heap::print()  // Prints all the elements in the heap.
{
  cout << endl;
  
  for (int i = 0; i < buffer.size(); i++) {
    cout << buffer[i] << " ";
  }
  cout << endl;
}

int heap::getLChild(int parentIdx) // Helper function that returns the index of the left child of the index given.
{
  return 2 * parentIdx + 1;
}

int heap::getRChild(int parentIdx) // Helper to get the index of the right child of the given index.
{
  return 2 * parentIdx + 2;
}

int heap::getParent(int childIdx) // Helper to get the index of the parent of the given index.
{
  return (childIdx - 1) / 2;
}

bool heap::hasLChild(int index) // Helper to identify if the index has a left child.
{
  if (getLChild(index) < buffer.size()) {
    return true;
  }
  return false;
}

bool heap::hasRChild(int index) // Helper to identify if the index has a right child.
{
  if (getRChild(index) < buffer.size()) {
    return true;
  }
  return false;
}

bool heap::hasParent(int index) // Helper to identify if the index has a parent.
{
  if (getParent(index) >= 0) {
    return true;
  }
  return false;
}

std::string heap::leftChild(int index) // Returns the value of the left child.
{
  return buffer[getLChild(index)];
}

std::string heap::rightChild(int index) // Returns the value of the right child.
{
  return buffer[getRChild(index)];
}

std::string heap::parent(int index) // Returns the value of the parent.
{
  return buffer[getParent(index)];
}

void heap::fixHeapUp() // Fixes the order of the nodes in the heap starting from the bottom. (useful for inserts)
{
  int idx = (buffer.size() - 1);
  while (hasParent(idx) && (parent(idx) > buffer[idx])) {
    swap(getParent(idx), idx);
    idx = getParent(idx);
  }
}

void heap::fixHeapDown() // Fixes the heap order from the top down. (useful for removing the top element)
{
  int idx = 0;
  while (hasLChild(idx)) {
    int smallerChild = getLChild(idx);
    if (hasRChild(idx) && rightChild(idx) < leftChild(idx)) {
      smallerChild = getRChild(idx);
    }

    if (buffer[idx] < buffer[smallerChild]) {
      break;
    }
    else {
      swap(idx, smallerChild);
    }
    idx = smallerChild;
  }
}
