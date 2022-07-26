#include <iostream>
#include <vector>

std::vector<int> qsort(std::vector<int> v){
	if (v.size() < 2){
		return v;
	} else {
		std::vector<int> less, more;
		int base = v[v.size()/2];
		for(const int& i : v){
			if(i == base) continue;
			if (i > base){
				more.push_back(i);
			} else {
				less.push_back(i);
			}
		}
		std::vector<int> sorted_less = qsort(less);
		std::vector<int> sorted_more = qsort(more);
		sorted_less.push_back(base);
		sorted_less.insert(sorted_less.end(), sorted_more.begin(), sorted_more.end());

		return sorted_less;
	}
}

int main(){
	std::vector<int> tst = {1, 4, 5, 2, 3, 5};
	std::vector<int> sorted = qsort(tst);
	for (const int& i : sorted){
		std::cout << i << " ";
	}

	return 0;
}