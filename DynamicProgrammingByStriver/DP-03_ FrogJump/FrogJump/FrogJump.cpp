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