/*
Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. 
At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.
*/

#include <iostream>

int main() {
	int n = 3;

	int prev2 = 1;
	int prev = 1;

	for (int i = 2; i <= n; i++) {
		int curr_i = prev2 + prev;
		prev2 = prev;
		prev = curr_i;
	}

	std::cout << prev;

	return 0;
}

/*
Output:
3
*/
