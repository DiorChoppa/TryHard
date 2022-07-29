#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

int main() {
	std::unordered_map<std::string, float> book = {
		{"apple", 0.67},
		{"milk", 1.49},
		{"avocado", 1.49}
	};

	std::map<std::string, float> book_new = {
		{"apple", 0.67},
		{"milk", 1.49},
		{"avocado", 1.49}
	};

	for (std::pair<std::string, float> pair : book){
		std::cout << pair.first << ": " << pair.second << "$" << std::endl;
	}

	std::cout << "----------------------" << std::endl;

	for (std::pair<std::string, float> pair : book_new){
		std::cout << pair.first << ": " << pair.second << "$" << std::endl;
	}

	return 0;
}