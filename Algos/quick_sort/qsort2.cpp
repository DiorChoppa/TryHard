#include <iostream>
#include <vector>

template <typename T>
std::vector<T> qsort(std::vector<T>& v){
	if(v.size() < 2) return v;
	
	const T* pivot = &v.front() + v.size() / 2 - 1;
	std::vector<T> less, greater;

	for (const T* item = &v.front(); item <= &v.back(); item++){
		if (item == pivot) continue;
		if (*item <= *pivot) less.push_back(*item);
		else greater.push_back(*item);
	}
	std::vector<T> less_sorted = qsort(less);
		std::vector<T> greater_sorted = qsort(greater);

		less_sorted.push_back(*pivot);
		less_sorted.insert(less_sorted.end(), greater_sorted.begin(), greater_sorted.end());

		return less_sorted;
}

int main() {
    std::vector<int> arr = {69, 60, 38, 82, 99, 15, 8, 94, 30, 42, 35, 40, 63, 1, 49, 66, 93, 83, 20, 32, 87, 6, 78, 17, 2, 61, 91, 25, 7, 4, 97, 31, 23, 67, 95, 47, 55, 92, 37, 59, 73, 81, 74, 41, 39};
    std::vector<int> sorted;
	sorted = qsort(arr);
    for (int num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

	return 0;
}