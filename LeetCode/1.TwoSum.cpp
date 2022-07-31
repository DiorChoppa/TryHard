#include <iostream>
#include <vector>

std::vector<int> Solution(std::vector<int>& nums, int target){
	for (ptrdiff_t i{0}; i < nums.size(); i++){
		for (ptrdiff_t j{i + 1}; j < nums.size(); j++){
			if (nums[i] + nums[j] == target){
				std::vector<int> result;
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
	return {0, 0};
}

int main() {
	std::vector<int> v1 = {2,7,11,15};
	std::vector<int> v2 = {3,2,4};
	std::vector<int> v3 = {3,3};
	
	std::vector<int> res1 = Solution(v1, 9);
	std::vector<int> res2 = Solution(v2, 6);
	std::vector<int> res3 = Solution(v3, 6);

	for (const int& i : res1){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (const int& i : res2){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (const int& i : res3){
		std::cout << i << " ";
	}
	std::cout << std::endl;
}