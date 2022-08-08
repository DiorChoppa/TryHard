#include <iostream>
#include <vector>

int main(){
	int n, k;
	std::vector<int> v;
	std::cin >> n;
	while(n--){
		int a;
		std::cin >> a; v.push_back(a);
	}
	std::cin >> k;

	for(int i = 0; i < v.size(); i++){
		for(int j = i + 1; j < v.size(); j++){
			if (v[i] + v[j] == k){
				std::cout << v[i] << " " << v[j];
				return 0;
			}
		}
	}
	std::cout << "None";
	return 0;
}