#pragma once
#include <iostream>

template <typename Type>
class CustomArrayList {
private:
	Type* data;
	int size{ 0 };
	int capacity{ 10 };
public:
	CustomArrayList() {
		data = new Type[capacity];
	}

	~CustomArrayList() {
		delete[] data;
	}

	CustomArrayList(const CustomArrayList<Type>& other) {
		capacity = other.capacity;
		size = other.size;
		data = new Type[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}

	CustomArrayList operator=(const CustomArrayList<Type>& other) {
		delete[] data;
		capacity = other.capacity;
		size = other.size;
		data = new Type[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}

	Type at(int index) {
		if ((index < size) && (index >= 0)) {
			return data[index];
		}
		throw "Out of bounds";
	}

	void set(int index, Type value) {
		if ((index < size) && (index >= 0)) {
			data[index] = value;
		}
		else {
			throw "Out of bounds";
		}
	}

	int getSize() { //O(1)
		return size;
	}

	void append(Type value) { //O(1)
		if (size == capacity) {
			this->expand();
		}
		data[size++] = value;
	}

	void expand() {
		Type* tmp = new Type[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
		tmp = nullptr;
		capacity *= 2;
	}

	Type& operator[](int index) {
		if ((index < size) && (index >= 0)) {
			return data[index];
		}
		else {
			throw "Out of bounds";
		}
	}

	// Method for finding the first index x with a given element at
	// index x and a second given element at index x+1.
	// Returns -1 if such a pair does not exist.

	//O(N^2)
	//3N^2 + 1
	//This method is not efficient. The big problem is the nested for loop in the second line. 
	//A loop inside a loop means that this method is O(N^2).
	int findPair(Type first, Type second) {//N(N(3)) + 1
		for (int i = 0; i < size; i++) { //N(N(3))
			for (int j = 0; j < size; j++) { //N(3 for branch)
				if (i + 1 == j) { //1 + (2 for branch)
					if (data[i] == first && data[j] == second) { //1 + (1 for branch)
						return i; //1
					}
				}
			}
		}
		return -1; //1
	}

	//O(N)
	//2N +1
	//The given method can be improved pretty easily. The most obvious improvement is to remove the 
	//nested loop. It isn't needed in the first place and just makes the method less efficient. 
	//Removing it brings the complexity from O(N^2) down to O(N)
	//Additionally, the first if statement can be removed which lightens the load on the for loop.
	//Finally, the second if statement can be adjusted, removing the variable j.
	int findPairImproved(Type first, Type second) { //N(2) + 1
		for (int i = 0; i < size; i++) { // N(2)
			if (data[i] == first && data[i+1] == second) { //1 + (1 for branch)
					return i; //1
			}
		}
		return -1;//1
	}

	template <typename Type>
	friend std::ostream& operator<<(std::ostream& out, const CustomArrayList<Type>& myList);
};

template <typename Type>
std::ostream& operator<<(std::ostream& out, const CustomArrayList<Type>& myList) {
	out << "[";
	for (int i = 0; i < myList.size; i++) {
		out << myList.data[i] << " ";
	}
	out << "]";
	return out;
}
