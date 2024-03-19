/*
Problem Statement:
Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
At a time the frog can climb either one or two steps. A height[N] array is also given. 
Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), 
where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> height{ 30, 10, 60, 10, 60, 50 };

	int n = height.size();

	int prev = 0;
	int prev2 = 0;
	for (int i = 2; i < n;i++) {
		int jumpTwo = INT_MAX;
		int jumpOne = prev + abs(height[i] - height[i-1]);
		if (i > 1) {
			jumpTwo = prev2 + abs(height[i] - height[i-2]);
		}

		int cur_i = std::min(jumpOne, jumpTwo);
		prev2 = prev;
		prev = cur_i;
	}
	std::cout << prev << std::endl;
	return 0;
}

/*
Output:
40
*/
