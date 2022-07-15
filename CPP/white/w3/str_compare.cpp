#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool compare(std::string a, std::string b){
	std::string ta = a;
	std::string tb = b;
	for (auto& c : ta){
		c = std::tolower(c);
	}
	for (auto& c : tb){
		c = std::tolower(c);
	}
	return ta < tb;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);

	for (auto& i : v){
		std::cin >> i;
	}
	sort(begin(v), end(v), compare);

	for (auto& s : v){
		std::cout << s;
	}

	return 0;
}