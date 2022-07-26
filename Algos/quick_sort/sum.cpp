#include <iostream>
#include <vector>

template <typename T>
T sum(const std::vector<T>& v){
	T sum = 0;
	for (const T& i : v){
		sum += i;
	}
	return sum;
}

int main() {
	std::vector<int> arr_int = {1, 2, 3, 4};
	std::vector<float> arr_float = {0.1, 0.2, 0.3, 0.4, 0.5};

	std::cout << "Sum int: " << sum(arr_int) << std::endl;
	std::cout << "Sum float: " << sum(arr_float) << std::endl;
	
	return 0;
}
