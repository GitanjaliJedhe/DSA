/*
Problem Statement:
A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. 
Therefore the first and the last house are adjacent to each other. 
The security system in the street is such that if adjacent houses are robbed, the police will get notified.
Given an array of integers “Arr” which represents money at each house, 
we need to return the maximum amount of money that the thief can rob without alerting the police.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Function to solve the problem using dynamic programming
int solve(std::vector<int>& arr) {
	int n = arr.size();

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

long long int robStreet(int n, std::vector<int> &arr) {
	std::vector<int> arr1;
	std::vector<int> arr2;

	if (n == 1)
		return arr[0];

	for (int i = 0; i < n; i++) {
		if (i != 0) { 
			arr1.push_back(arr[i]); 
		}

		if (i != n - 1) {
			arr2.push_back(arr[i]);
		}
	}

	long long int ans1 = solve(arr1);
	long long int ans2 = solve(arr2);

	return std::max(ans1, ans2);
}

int main() {
	std::vector<int> arr{ 1,5,1,2,6 };

	int n = arr.size();

	// Call the solve function and print the result
	std::cout << robStreet(n, arr);

	return 0;
}

/*
Output:
11
*/
