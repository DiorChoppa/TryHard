#include <iostream>
#include <vector>
#include <string>

void EnsureEqual(const std::string& left, const std::string& right){
	if (left == right){
		std::cout << left << " " << right << std::endl;
	} else {
		throw std::runtime_error(left + " != " + right);
	}
};

int main(){
	std::string a, b;
	std::cin >> a >> b;

	try {
		EnsureEqual(a, b);
	} catch (const std::exception& ex){
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	
	return 0;
}