#include "heap.h"

using namespace std;


void heap::swap(int iOne, int iTwo)
{
	string temp = buffer[iOne];
	buffer[iOne] = buffer[iTwo];
	buffer[iTwo] = temp;
}

heap::heap()
{
}

int heap::size()
{
	return buffer.size();
}

void heap::insert(std::string value)
{
	buffer.push_back(value);
	fixHeapUp();
}

void heap::remove_min()
{
	buffer[0] = buffer[buffer.size() - 1];
	buffer.pop_back();
	fixHeapDown();
}

string heap::min()
{
	return buffer[0];
}

void heap::print()
{
	cout << endl;

	for (int i = 0; i < buffer.size(); i++) {
		cout << buffer[i] << " ";
	}
	cout << endl;
}

int heap::getLChild(int parentIdx)
{
	return 2 * parentIdx + 1;
}

int heap::getRChild(int parentIdx)
{
	return 2 * parentIdx + 2;
}

int heap::getParent(int childIdx)
{
	return (childIdx - 1) / 2;
}

bool heap::hasLChild(int index)
{
	if (getLChild(index) < buffer.size()) {
		return true;
	}
	return false;
}

bool heap::hasRChild(int index)
{
	if (getRChild(index) < buffer.size()) {
		return true;
	}
	return false;
}

bool heap::hasParent(int index)
{
	if (getParent(index) >= 0) {
		return true;
	}
	return false;
}

std::string heap::leftChild(int index)
{
	return buffer[getLChild(index)];
}

std::string heap::rightChild(int index)
{
	return buffer[getRChild(index)];
}

std::string heap::parent(int index)
{
	return buffer[getParent(index)];
}

void heap::fixHeapUp()
{
	int idx = (buffer.size() - 1);
	while (hasParent(idx) && (parent(idx) > buffer[idx])) {
		swap(getParent(idx), idx);
		idx = getParent(idx);
	}
}

void heap::fixHeapDown()
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
