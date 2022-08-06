#include <iostream>

int main() {
	std::string a = "FISH", b = "FOSH";
	const size_t &size_a = a.size(), &size_b = b.size();
	
	size_t **table = new size_t *[size_a];
	for(size_t k = 0; k < size_a; k++){
		table[k] = new size_t[size_b]{};
	}

	for(size_t i = 0; i < size_a; i++){
		for(size_t j = 0; j < size_b; j++){
			if (a[i] == b[j]){
				if (i && j){
					table[i][j] = table[i - 1][j - 1] + 1;
				} else {
					table[i][j] = 1;
				}
			} else {
				if (i && j){
					table[i][j] = table[i - 1][j] > table[i][j - 1] ? table[i - 1][j] : table[i][j - 1];
				}
				else if (!i && j){
					table[i][j] = table[i][j - 1];
				}
				else if (i && !j){
					table[i][j] = table[i - 1][j];
				}
				else table[i][j] = 0;
			}
		}
	}

	for(size_t i = 0; i < size_a; i++){
		std::cout << '[';
		for(size_t j = 0; j < size_b; j++){
			std::cout << table[i][j] << " ";
		}
		std::cout << ']' << std::endl;
	}
	
	return 0;
}