#include <iostream>
#include <vector>

template <typename T>
T r_count(std::vector<T> v){
	if (v.empty()) return 0;

	v.pop_back();
	return r_count(v) + 1;
}

int main() {
	std::vector<int> arr_int = {1, 2, 3, 4};
	std::vector<float> arr_float = {0.1, 0.2, 0.3, 0.4, 0.5};

	std::cout << "Sum int: " << r_count(arr_int) << std::endl;
	std::cout << "Sum float: " << r_count(arr_float) << std::endl;
	
	return 0;
}