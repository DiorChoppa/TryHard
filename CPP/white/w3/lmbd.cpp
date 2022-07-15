#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int thr;
	std::vector<int> v(5); 
	std::cin >> thr;
	int n = 5;
	while (n-- != 0){
		int m;
		std::cin >> m;
		v.push_back(m);
	}

	std::cout << std::count_if(begin(v), end(v), [thr](int x){
		if(x > thr){
			return true;
		}
		return false;
	});
}