#include <iostream>
#include <vector>

int findSmallest(std::vector<int>& v){
	int value = v[0];
	int index = 0;

	for (int i = 0; i < v.size(); i++){
		if (v[i] < value) {
			value = v[i];
			index = i;
		}
	}
	return index;
}

std::vector<int> selectionSort(std::vector<int> v){
	std::vector<int> mew;
	int min;

	while(!v.empty()) {
		min = findSmallest(v);
		mew.push_back(v[min]);
		v.erase(begin(v) + min);
	}
	return mew;
}

int main () {
	std::vector<int> started = {2, 1, 0, 3, -1, 5, 100, -99};
	std::vector<int> sorted = selectionSort(started);

	for (const auto& i : sorted){
		std::cout << i << " ";
	}
	
	return 0;
}