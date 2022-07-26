#include <iostream>
#include <vector>

template <typename T>
T reqursive_sum(std::vector<T> v){
	if (v.empty()) return 0;

	T last_num = v.back();
	v.pop_back();
	return last_num+reqursive_sum(v);
}

int main() {
	std::vector<int> arr_int = {1, 2, 3, 4};
	std::vector<float> arr_float = {0.1, 0.2, 0.3, 0.4, 0.5};

	std::cout << "Sum int: " << reqursive_sum(arr_int) << std::endl;
	std::cout << "Sum float: " << reqursive_sum(arr_float) << std::endl;
	
	return 0;
}