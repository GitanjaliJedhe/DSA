/*
Problem Statement:
Given an array of �N�  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Function to solve the problem using dynamic programming
int solve(int n, std::vector<int> &arr) {
	int prev = arr[0]; // Initialize the maximum sum ending at the previous element
	int prev2 = 0; // Initialize the maximum sum ending two elements ago

	for (int i = 1; i < n; i++) {
		int pick = arr[i]; // Maximum sum if we pick the current element
		if (i > 1) {
			pick += prev2; // Add the maximum sum two elements ago
		}

		int nonPick = 0 + prev; // Maximum sum if we don't pick the current element

		int cur_i = std::max(pick, nonPick); // Maximum sum ending at the current element
		prev2 = prev; // Update the maximum sum two elements ago
		prev = cur_i; // Update the maximum sum ending at the previous element
	}

	return prev; // Return the maximum sum
}

int main() {
	std::vector<int> arr{2, 1, 4, 9};

	int n = arr.size();

	// Call the solve function and print the result
	std::cout << solve(n, arr);

	return 0;
}

/*
Output:
11
*/
