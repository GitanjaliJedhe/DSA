/*
Problem Statement: 
Given an array arr of distinct integers, print all permutations of String/Array.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
	void recurPermute(int index, std::vector<int> &nums, std::vector<std::vector<int>> &ans) {
		if (index == nums.size()) {
			ans.push_back(nums);
			return;
		}

		for (int i = index; i < nums.size(); i++) {
			std::swap(nums[index], nums[i]);
			recurPermute(index+1, nums, ans);
			std::swap(nums[index], nums[i]);
		}
	}

public:
	std::vector<std::vector<int>> permute(std::vector<int>& nums) {
		std::vector<std::vector<int>> ans;

		recurPermute(0, nums, ans);

		return ans;
	}
};

int main() {
	Solution obj;
	std::vector<int> v{1,2,3};
	std::vector<std::vector<int>> sum = obj.permute(v);

	std::cout << "All Permutations are" << std::endl;
	for (int i = 0; i < sum.size(); i++) {
		for (int j = 0; j < sum[i].size(); j++) {
			std::cout << sum[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

/*
Output:
All Permutations are
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
3 1 2
*/
