#include <iostream>
#include <vector>

using namespace std;

int f(int n, std::vector<int>& dp) {
	if (n <= 1) {
		return n;
	}

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = f(n-1,dp) + f(n-2, dp);
}

int main() {

	int n = 5;

	std::vector<int> dp(n+1,-1);

	cout << f(n, dp);

	return 0;
}

/*
Output:
5
*/
