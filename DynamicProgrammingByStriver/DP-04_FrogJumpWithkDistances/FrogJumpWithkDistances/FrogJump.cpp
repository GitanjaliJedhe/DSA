/*
Problem Statement:
This is a follow-up question to “Frog Jump” discussed in the previous article. 
In the previous question, the frog was allowed to jump either one or two steps at a time. 
In this question, the frog is allowed to jump up to ‘K’ steps at a time. 
If K=4, the frog can jump 1,2,3, or 4 steps at every index.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUntil(int n, std::vector<int>& height, std::vector<int>& dp, int k) {
	dp[0] = 0;

	// Loop through the array to fill in the dp array
	for (int i = 1; i < n; i++) {
		int mmSteps = INT_MAX;

		// Loop to try all possible jumps from '1' to 'k'
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				int jump = dp[i - j] + abs(height[i] - height[i - j]);
				mmSteps = std::min(jump, mmSteps);
			}
		}
		dp[i] = mmSteps;
	}
	return dp[n - 1]; // The result is stored in the last element of dp
}

// Function to find the minimum cost to reach the end of the array
int solve(int n, std::vector<int>& height, int k) {
	std::vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
	return solveUntil(n, height, dp, k);
}

int main() {
	std::vector<int> height{ 30, 10, 60, 10, 60, 50 };

	int n = height.size();
	int k = 2;
	std::vector<int> dp(n, -1); // Initialize a memoization array for the main function
	std::cout << solve(n, height, k) << std::endl; // Print the result of the solve function

	return 0;
}

/*
Output:
40
*/
