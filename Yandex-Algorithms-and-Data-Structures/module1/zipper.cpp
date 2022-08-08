#include <iostream>
#include <vector>

int main() {
	int n;
	std::vector<int> a, b, result;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		std::cin >> temp;
		a.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		int temp;
		std::cin >> temp;
		b.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		result.push_back(a[i]);
		result.push_back(b[i]);
	}
	for(const int& i : result){
		std::cout << i << " ";
	}

	return 0;
}