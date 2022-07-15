#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool compare(int x, int y){
	return std::abs(x) < std::abs(y);
}

int main(){
	int n, t;
	std::cin >> n;
	std::vector<int> v(n);

	for(int& s : v){
		std::cin >> s;
	}
	std::sort(begin(v), end(v), compare);

	for(const auto& i : v){
		std::cout << i << " ";
	}

	return 0;
}