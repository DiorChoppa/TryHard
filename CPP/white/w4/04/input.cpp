#include <iostream>
#include <fstream>
#include <string>

void ReadAll(const std::string& path){
	std::ifstream input(path);
	if (input){
		std::string line;
		while (std::getline(input, line)){
			std::cout << line << std::endl;
		}
	}
	else std::cout << "Error!";
}

int main() {
	std::string in = "input.txt";
	std::string out = "output.txt";
	std::string line;

	std::ifstream input(in);
	std::ofstream output(out);
	if (input){
		while (std::getline(input, line)){
			output << line << std::endl;
		}
	}
	else std::cout << "Error!";

	ReadAll(out);
	return 0;
}