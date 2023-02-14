#include <iostream>
#include "CustomArrayList.h"
using namespace std;


int main() {
	CustomArrayList<int> arr;
	arr.append(0);
	arr.append(1);
	arr.append(2);
	arr.append(3);
	arr.append(4);
	arr.append(5);
	arr.append(6);
	cout << arr.findPairImproved(4, 2);
}
