//Elijah Turany
//CS244-002

//O(N^2)
//3N^2 + 1
//This method is not efficient. The big problem is the nested for loop in the second line. 
//A loop inside a loop means that this method is O(N^2).
int findPair(T first, T second) {//N(N(3)) + 1
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
int findPairImproved(T first, T second) { //N(2) + 1
	for (int i = 0; i < size; i++) { // N(2)
		if (data[i] == first && data[i + 1] == second) { //1 + (1 for branch)
			return i; //1
		}
	}
	return -1;//1
}