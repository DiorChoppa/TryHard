#include <iostream>
#include <algorithm>
#include <vector>

int binary_search(const std::vector<int>& v, const int& item, bool sorted = true){
	int low = 0;
	int high = v.size() - 1;
	int mid;

	if (sorted){
		while (low <= high){
			mid = (low + high) / 2;
			if (item == v[mid]) return mid;
			if (item > v[mid]){
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return -1;
	} else {
		std::vector<int> help = v;
		std::sort(begin(help), end(help));

		while (low <= high){
			mid = (low + high) / 2;
			if (item == v[mid]) return mid;
			if (item > v[mid]){
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return -1;
	}
}

int main (){
	std::vector<int> check;

	for (int i = 1; i <= 100; i++){
		check.push_back(i);
	}

	std::cout << binary_search(check, 3) + 1 << std::endl;
	std::cout << binary_search(check, 51) + 1 << std::endl;
	std::cout << binary_search(check, 99) + 1 << std::endl;
	std::cout << binary_search(check, -2) + 1 << std::endl;
	
	return 0;
}