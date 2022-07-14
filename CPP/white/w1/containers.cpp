#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
	std::string s = "abcdefg";
	for (char &c : s){
		std::cout << c << ", ";
	}
	std::cout << std::endl;

	std::vector<int> nums = {1, 5, 6, 5, 9};
	for (auto &c : nums){
		std::cout << c << ", ";
	}
	std::cout << std::endl;

	int quantity = std::count(begin(nums), end(nums), 5);
	std::cout << "There are " << quantity << " fives" << std::endl;

	std::vector<std::string> words = {"hello", "world", "milk"};
	std::sort(begin(words), end(words));
	for(auto x : words){
		std::cout << x << " ";
	}
	
	return 0;
}