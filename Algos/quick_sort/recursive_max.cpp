#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
T max(std::vector<T> v) {
	if(v.empty()) throw std::invalid_argument("Empty sequence!");
	if(v.size() == 1) return v.at(0);

	T back = v.back();
	v.pop_back();

	T sub_max = max(v);
	return back > sub_max? back : sub_max;
}

int main() {
	std::vector<int> arr_int = {1, 2, 3, 4};
	std::vector<float> arr_float = {0.1, 0.2, 0.3, 0.4, 0.5};

	std::cout << "Max int: " << max(arr_int) << std::endl;
	std::cout << "Max float: " << max(arr_float) << std::endl;
	
	return 0;
}