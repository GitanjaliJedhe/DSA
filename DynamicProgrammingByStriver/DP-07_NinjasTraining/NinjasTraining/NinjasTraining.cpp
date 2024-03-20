/*
Problem Statement: 
A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. 
There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. 
We need to find the maximum merit points the ninja can attain in N Days.
We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. 
Our task is to calculate the maximum number of merit points that the ninja can earn.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the maximum points for ninja training
int ninjaTraining(int n, std::vector<std::vector<int>> &points) {
	// Initialize a vector to store the maximum points for the previous day's activities
	std::vector<int> prev(4, 0);

	// Initialize the DP table for the first day (day 0)
	prev[0] = std::max(points[0][1], points[0][2]);
	prev[1] = std::max(points[0][0], points[0][2]);
	prev[2] = std::max(points[0][0], points[0][1]);
	prev[3] = std::max(points[0][0], std::max(points[0][1], points[0][2]));

	// Iterate through the days starting from day 1
	for (int day = 1; day < n; day++) {
		// Create a temporary vector to store the maximum points for the current day's activities
		std::vector<int> temp(4, 0);

		for (int last = 0; last < 4; last++) {
			temp[last] = 0;
			// Iterate through the tasks for the current day
			for (int task = 0; task <= 2; task++) {
				if (task != last) {
					// Calculate the points for the current activity and add it to the
					// maximum points obtained on the previous day (stored in prev)
					temp[last] = std::max(temp[last], points[day][task] + prev[task]);
				}
			}
		}
		// Update prev with the maximum points for the current day
		prev = temp;
	}
	// The maximum points for the last day with any activity can be found in prev[3]
	return prev[3];
}

int main() {

	// Define the points matrix
	std::vector<std::vector<int>> points = {{10,40,70}, {20,50,80}, {30,60,90}};

	int n = points.size(); // Get the number of days

	// Call the ninjaTraining function to find the maximum points and print the result
	std::cout << ninjaTraining(n, points) << std::endl;;

	return 0;
}

/*
Output:
210
*/
